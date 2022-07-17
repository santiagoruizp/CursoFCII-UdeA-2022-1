
#include "complejo.h"

using namespace std;

// Recibe a y b parte real y compleja respectivamente
complejo::complejo(double a, double b){

   //cout<<"Objeto creado"<<endl;
   AsignarDatos(a , b);   

}

// Al recibir a y b se puede sobreescribir el número complejo sin cambiar su instanciación
void complejo::AsignarDatos(double a, double b){

   ParteReal = a;
   ParteImaginaria = b;
}

// Retorna la parte real del objeto
double complejo::ObtenerParteReal(){

   return ParteReal;

}

// Retorna la parte compleja del objeto
double complejo::ObtenerParteImaginaria(){

   return ParteImaginaria;

}

// Imprime el número complejo
void complejo::ImpresiondeNumero(){

   // Para una adecuada impresión del signo
   if (ParteImaginaria >= 0)
      cout<<endl<<ParteReal<<"+"<<ParteImaginaria<<"i"<<endl;
   else
      cout<<endl<<ParteReal<<ParteImaginaria<<"i"<<endl;
}

// Suma
complejo complejo::SumaComplejos(complejo n, complejo m){

   complejo suma(n.ObtenerParteReal() + m.ObtenerParteReal(), n.ObtenerParteImaginaria() + m.ObtenerParteImaginaria());
   return suma;

}

// Resta del operando derecho al izquierdo
complejo complejo::RestaComplejos(complejo n, complejo m){

   complejo resta(n.ObtenerParteReal() - m.ObtenerParteReal(), n.ObtenerParteImaginaria() - m.ObtenerParteImaginaria());
   return resta;

}


// Producto
complejo complejo::ProductoComplejos(complejo n, complejo m){

   complejo prod(n.ObtenerParteReal()*m.ObtenerParteReal() - n.ObtenerParteImaginaria()*m.ObtenerParteImaginaria(),        		
   		   n.ObtenerParteReal()*m.ObtenerParteImaginaria() + m.ObtenerParteReal()*n.ObtenerParteImaginaria());
   return prod;

}

// División entre operando derecho e izquierdo
complejo complejo::DivisionComplejos(complejo n, complejo m){

   complejo div( (n.ObtenerParteReal()*m.ObtenerParteReal() + n.ObtenerParteImaginaria()*m.ObtenerParteImaginaria())/	 (m.ObtenerParteReal()*m.ObtenerParteReal() + m.ObtenerParteImaginaria()*m.ObtenerParteImaginaria()) , (m.ObtenerParteReal()*n.ObtenerParteImaginaria() - n.ObtenerParteReal()*m.ObtenerParteImaginaria())/(m.ObtenerParteReal()*m.ObtenerParteReal() + m.ObtenerParteImaginaria()*m.ObtenerParteImaginaria()));
   
   return div;

}

// Módulo
double complejo::Modulo(){

   return sqrt(ParteReal*ParteReal + ParteImaginaria*ParteImaginaria);

}

// Módulo
complejo complejo::Conjugado(){

   complejo c = complejo(ParteReal, -ParteImaginaria);
   return c;

}




