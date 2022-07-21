
#include<iostream>
#include<iomanip>
#include<cmath>


class complejo{

   public:
      complejo(double, double);
      void AsignarDatos(double, double);
      double ObtenerParteReal();  
      double ObtenerParteImaginaria();
      void ImpresiondeNumero();
      complejo SumaComplejos(complejo, complejo);
      complejo RestaComplejos(complejo,complejo);
      complejo ProductoComplejos(complejo,complejo);
      complejo DivisionComplejos(complejo, complejo);
      double Modulo();
      complejo Conjugado();
           
   private: 
      double ParteReal;
      double ParteImaginaria;
};





