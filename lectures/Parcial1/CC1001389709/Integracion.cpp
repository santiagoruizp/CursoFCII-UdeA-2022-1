#include "Integracion.h"

// func: Función a integrar
// a : Extremo izquierdo del intervalo
// b : Extremo derecho del intervalo


Integracion::Integracion(float (*func)(float), float a, float b){
   
   // Mensaje que indica la creación del objeto
   cout<<"Clase para realizar integración numérica con subintervalos regulares."<<endl;
   
   // Mensaje que indica un error en el ingreso de los extremos del intervalo
   if (b<a)
      cout<<"Se debe cumplir que el valor extremo del intervalo de la derecha sea mayor que el de la izquierda. Los resultados pueden ser erroneos"<<endl;
   
  
   // Se inicializan las variables privadas
   Nsteps = 100;
   h = (b-a)/Nsteps;
   
   // Se evalua la función en los extremos de la partición del intervalo
   for (int j = 0; j <= Nsteps+1; j++){
      eval[j] = func(a + j*h);
   }   
}

//---------------------------------------------------------------------------------------------------------

float Integracion::TrapezoidIntegral(){

   float area = 0;
   
   // Regla del trapecio
   for (int i = 0; i <= Nsteps-1; i++){
      area += h/2.0*(eval[i] + eval[i+1]);
   }
   
   return area;
}

//---------------------------------------------------------------------------------------------------------

float Integracion::SimpsonIntegral(){

   float area = eval[0] + eval[Nsteps];
   
   // Regla de Simpson
   for (int i = 1; i <= Nsteps/2; i++){
      area += 4.0*eval[2*i-1];
   }
   
   for (int i = 1; i <= Nsteps/2-1; i++){
      area += 2.0*eval[2*i];
   }
   
   return area*h/3.0;
}

//---------------------------------------------------------------------------------------------------------





























