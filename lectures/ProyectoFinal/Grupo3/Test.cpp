
#define __STDCPP_WANT_MATH_SPEC_FUNCS__ 1
#include <iostream>
using namespace std;
#include "WoodSaxon.h"
#include <math.h>
#include <cmath>

int main(){

   // Energía del rayo de neutrones incidente
   double E=10.0;

   // Calcio 40
   unsigned int A = 40,  Z=20;
   double Mass=40.078;
   string Element = "Ca";
   
   // Plata 107
   //unsigned int A = 107,  Z=47;
   //double Mass=107.8682;
   //string Element = "Ag";

   // Uranio 238
   //unsigned int A = 238,  Z=92;
   //double Mass=238.05078826;
   //string Element = "U";

   // Hierro 56
   unsigned int A = 56,  Z=26;
   double Mass=55.845 ;
   string Element = "Fe";


   // Ejecución de los ejemplos
   WoodSaxon Ejemplo1(E,Mass,A,Z,Element);
   Ejemplo1.Calcular();
   Resonancias Ejemplo2(Mass,A,Z,Element);
 
   return 0;
}