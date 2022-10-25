
#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#include<cmath>
#include<iomanip>
#include<fstream>
#include <math.h>
#include "WoodSaxon.h"

// Constructor de la clase WoodSaxon
// E0: Energía del rayo incidente
// Mass: Masa atómica del núcleo objetivo en a.m.u
// A0: Número másico del núcleo objetivo
// Z0: Número atómico del núcleo objetivo
// Element: String para generar los archivos
WoodSaxon:: WoodSaxon(double E0, double Mass0, unsigned int A0, unsigned int Z0, string Element){

   A=A0, E=E0, Z=Z0, Mass = Mass0, Elem = Element;            // Se asignan los valores a las variables privadas de la clase
   double hbar=6.4655, Mn=1.008665;                           // h barra en (MeVu)1/2 y masa del neutrón en a.m.u
   H2M=hbar*hbar*(Mn+Mass)/(2.0*Mn*Mass);                     // Constante del problema: hbar²/(2*Masa reducida)  
   k=sqrt(E/H2M);                                             // Número de onda del rayo incidente
   N=int(Rmax/dx);                                            // Número de puntos a resolver

   for (int i = 0; i < N; i++){                               // Se llena el vector de posiciones radiales
      r.push_back(i*dx);      
   }
}

// Función para realizar los cálculos. Genera archvivos con tablas de dσ/dΩ vs θ, r vs V(r) y σ vs l.
void WoodSaxon::Calcular(){

   Potencial();                                                              // Se llena el vector de potencial                   
   SigmaConv();                                                              // Se calcula el l de convergencia y el σ total
   SeccionEficazDif();                                                       // Se calcula la sección eficaz diferencial dσ/dΩ
   int Eint = int(E);
   Guardar(Elem+to_string(A)+"_"+to_string(Eint)+"MeV_Potencial.txt",1);        // Se guardan los datos del potencial
   Guardar(Elem+to_string(A)+"_"+to_string(Eint)+"MeV_SigmaConv.txt",3);        // Se guardan los datos de la sección transversal total de convergencia
   Guardar(Elem+to_string(A)+"_"+to_string(Eint)+"MeV_dsdW.txt",2);             // Se guardan los datos de la sección transversal diferencial
}

// Función para calcular el potencial de Wood-Saxon
void WoodSaxon::Potencial(){

   double V1 = 56.3, V2 = 0.32, V3 = 24.0;      // Constantes del potencial en [MeV]
   double a = 0.75, r0 = 1.17, expmax = 700;    // Constantes del potencial en [fm]
   double R = r0*pow(A, 1.0/3.0);               // Radio del núcleo
   double V0= V1-V2*E-V3*(1.0-(2.0*Z)/A);       // Profundidad del pozo del potencial 
   
   for (int i = 0; i < N; i++){
      if ((r[i]-R)/a <= expmax){                        // Condicional para evtar un overflow
         V.push_back(-V0/(1.0 + exp((r[i]-R)/a)));      // Vector con los valores del potencial
      }
      else{
         V.push_back(0.0);
      }
   }
}

// Método de Numerov para resolver la ecuación de onda radial mediante diferencias finitas. El objetivo de esta función es el cálculo de la fase del scattering
// lp: Valor de momento angular  
void WoodSaxon::NumerovMethod(unsigned int lp){

   // U(r) es tal que la función de onda radial es R(r) = U(r)/r
   // U0 = U(r-h),  U1 = U(r),  U1 = U(r+h)

   // g(r) = 2m/hbar²(E - V(r)) - l(l+1)/r²
   // W0 = g(r-h),  W1 = g(r),  W1 = g(r+h)

   // A1, A2 son tales que el la fase del scattering es δ = arctan(A1/A2)
   // x es un término definido por conveniencia como x = k*(Rmax-dx)

   double W0,W1,W2, U0,U1,U2, R,A1,A2,x;      
   delta.clear();                          // Se eliminan las entradas del vector fase del scattering  

   for(int l=0; l<=lp;l++){                // Se suma sobre los valores de momento angular l = 0,...,lp    

      W0=(E-V[0])/H2M-l*(l+1)/(dx*dx);     // Valor de g(0) de acuerdo a su definición
      W1=(E-V[1])/H2M-l*(l+1)/(dx*dx);     // Valor de g(h) de acuerdo a su definición
      U0=0.0;                              // Se inicializa f(0) = 0 para garantizar la continuidad de R(r)
      U1=1.0;                              // Se inicializa f(h) = 1

      for(int i=1; i<N-1;i++){             // Método de Numerov

         R=r[i+1];
         W2= (E-V[i+1])/H2M-l*(l+1)/(R*R);
         U2=((2*U1)-U0-(((dx*dx)/12.0)*((10*W1*U1)+(W0*U0))))/(1+dx*dx*W2/12);
         W0=W1;
         W1=W2;
         U0=U1;
         U1=U2;
      }

      x=k*(Rmax-dx);                                                         // Variable de conveniencia
      A1=((Rmax-dx)*sph_bessel(l,x)*U1)-Rmax*sph_bessel(l,k*Rmax)*U0;        // Numerador de la fase del scattering
      A2=((Rmax-dx)*sph_neumann(l,x)*U1)-Rmax*sph_neumann(l,k*Rmax)*U0;      // Denominador de la fase del scattering
      delta.push_back(atan(A1/A2));                                          // Se almacena la fase del scattering 
   }
}

// Cálculo de la sección eficaz diferencial
void WoodSaxon::SeccionEficazDif(){

   // deg: Factor de conversión de radianes a grados
   // Ref: Parte real de la amplitud de dispersión f(θ)
   // Imf: Parte imaginaria de la amplitud de dispersión f(θ)
   // plth: Polinomio de Legendre evaluado en θ = 0

   double deg= M_PI/180,Ref,Imf,plth;
   dsigma.clear();

   for(int i=0; i<=180; i++){                // Loop sobre el ángulo θ con paso 1°
      
      theta.push_back(i*deg);
      Ref=0.0;
      Imf=0.0;
      for(int l=0;l<lp_conv+1;l++){         // Cálculo de la parte real e imaginaria de f(θ) hasta lp_conv
          
         plth = legendre(l,cos(theta[i]));
         Ref = Ref+ (0.5/k)*(2*l+1)*(sin(2*delta[l]))*plth;
         Imf = Imf+(1/k)*(2*l+1)*(pow(sin(delta[l]),2))*plth;
      }

      dsigma.push_back(Ref*Ref+Imf*Imf);    // Se calcula dσ/dΩ = Re(f(θ))**2 + Im(f(θ))**2 para el θ del ciclo

      if (i==0){
         sigma = (4*M_PI/k)*Imf*10;        // Se calcula la secciónn eficaz total σ = 4πh(0)/k 
      }
   }
}

// Función para determinar el lp de convergencia
// data: Nombre del archivo en el que se almacenan los datos
void WoodSaxon::SigmaConv(){

   // Imf: Parte imaginaria de la amplitud de dispersión f(θ)
   // plth: Polinomio de Legendre evaluado en θ = 0
   // lp_conv: Se almacena el valor de lp de convergencia
   // lp: valor recursivo de momento angular
   double Imf, plth;
   lp_conv = 0;
   unsigned int lp=1;

   while (lp_conv == 0){      

      NumerovMethod(lp);                     // Se calcula la función de onda radial para determinar la fase de scattering
      Imf=0.0;
      
      for(int l=0 ; l<lp+1 ; l++){           // Loop para calcular la parte imaginaria de f(θ) hasta lp 
      
         plth = legendre(l,cos(0));
         Imf = Imf+(1/k)*(2*l+1)*(pow(sin(delta[l]),2))*plth;
      }
      
      LP.push_back(lp);
      sigmarrayConv.push_back((4*M_PI/k)*Imf*10);                    // Se almacenan los valores de lp vs σ
                                             
      if (lp >= 2  && sigmarrayConv[lp-1] == sigmarrayConv[lp-2]){   // Condicional para determinar el lp de convergencia
         lp_conv = lp;
         sigma = sigmarrayConv[lp-1];
         break;
      }
      lp++;       
   }
}

// Función para guardar los datos
// data: Nombre del archivo
// elec: 1 para salvar el potencial y 2 para salvar dσ/dΩ
void WoodSaxon::Guardar(string data, int elec){
     
    ofstream outFile;                                             // Se crea el archivo para almacenar los datos
    outFile.open(data.c_str(), std::ofstream::out);

   if(elec == 1){                                                // Se guardan los datos del potencial
      outFile << "r" << "\t"<<"V(r)"<<"\n";
      for( int i=0 ; i<N ; i++ ){
         outFile << r[i] << "\t"<<V[i]<<"\n";
      }
   }
   if(elec == 2){                                               // Se guardan los datos de sección eficaz diferencial
      outFile << "theta" << "\t"<<"dsigma"<<"\n";
      for( int i=0 ; i<=180 ; i++ ){     
         outFile << theta[i] << "\t"<<dsigma[i]*10<<"\n";
      }
   }
   if (elec == 3) {                                              // Se guardan los datos de sección eficaz de convergencia
      outFile << "lp" << "\t"<<"sigma"<<"\n";
      for(int i=0; i<=lp_conv-1; i++){ 
         outFile << LP[i] << "\t"<< sigmarrayConv[i]<<"\n";
      }
   }
}

// Constructor de la clase Resonancias
// Mass: Masa atómica del núcleo objetivo en a.m.u
// A0: Número másico del núcleo objetivo
// Z0: Número atómico del núcleo objetivo
// Element: String para generar el archivos
// Genera un archvivo con tabla de σ vs E
Resonancias::Resonancias(double Mass0, unsigned int A0, unsigned int Z0, string Element){
   
   // dE : Tamaño del paso en energía
   // E : Valor de energía 
   double dE = 0.01, E;

   ofstream outFile;                                                      // Se crea el archivo para almacenar los datos                      
   string Filename = Element+to_string(A0)+"_"+"SigmaResonance.txt" ;
   outFile.open(Filename.c_str(), std::ofstream::out);
   outFile << "E" << "\t"<<"sigma"<<"\n";
 
   for (int s = 1; s <=5000; s++){                                 // Ciclo para el cálculo de sigma vs E 

      E = s*dE;                                                    // Valor de la energía

      WoodSaxon RecursiveObj(E, Mass0, A0, Z0, Element);           // Se inicializa un objeto de la clase WoodSaxon para tal cálculo
      RecursiveObj.Potencial();                                                                   
      RecursiveObj.SigmaConv(); 

      outFile << E << "\t"<< RecursiveObj.sigma <<"\n";           // Se guardan los datos
   }
}