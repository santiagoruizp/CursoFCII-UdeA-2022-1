#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Integracion{

   public: 
      Integracion(float (*func)(float), float, float);
      float TrapezoidIntegral();
      float SimpsonIntegral();
      
   private:
      // Variable para guardar longitud de intervalos.
      float h;
      // Variable para guardar el número de intervalos. 
      int Nsteps;
      // Lista de la evaluación de la función. 
      float eval[101];

};



