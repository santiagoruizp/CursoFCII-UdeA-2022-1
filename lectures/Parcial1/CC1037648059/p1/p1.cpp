#include<iostream>
#include<math.h>
#include<iomanip>

/* Se define la funcion para integrar */
#define f(x) 1/(1+pow(x,2))

using namespace std;
float simpson(float lower, float upper, int subInterval)
{
 float integration=0.0, stepSize, k;
 int i;

 /* Calculo */

 /* Encontrando el tamaño de la division */
 stepSize = (upper - lower)/subInterval;

 /* proceso de integracion segun la regla de simpson */
 integration = f(lower) + f(upper);

 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;

  if(i%2==0)
  {
    integration = integration + 2 * (f(k));
  }
  else
  {
    integration = integration + 4 * (f(k));
  }

 }

 integration = integration * stepSize/3;

 //cout<< endl <<"Required value of integration is: "<< integration<<endl;

 return integration;
}

float trapezoid(float lower, float upper, int subInterval)
{
float integration=0.0, stepSize, k;
int i;

/*procedimiento analogo*/
 stepSize = (upper - lower)/subInterval;

 integration = f(lower) + f(upper);

 for(i=1; i<= subInterval-1; i++)
 {
  k = lower + i*stepSize;
  integration = integration + 2 * (f(k));
 }

 integration = integration * stepSize/2;

 //cout<< endl<<"Required value of integration is: "<< integration;

 return integration;
}

int main(){
    cout<<"En este programa se ponen a prueba los métodos de integración numérica regidos por la Regla del";
    cout<<" trapezoide y Regla de Simpson."<<endl;
    cout<<"Para este menester se integrará la función 1/(1+x^2), esta función como tambien los parámetros de integración se pueden cambiar editando este programa."<<endl;
    cout<<"Se integrará esta función en el intervalo (1,0) para distintos subintervalos (pues el intervalo debe ser dividido como es comun en este tipo de procesos."<<endl;
    cout<<"Como la antiderivada de esta función es la tangente inversa, evaluado en los limites de integración la integral toma el valor exacto de π/4"<<endl;
    cout<<endl;
    cout<<"||\tNumero de subintervalos\t || Valor por Regla del Trapezoide || Valor por Regla de Simpson || Valor exacto  ||"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int j=1;j<16;j++){
        cout<<setprecision(4)<<"||\t\t  "<<j<<"\t\t ||\t\t"<<trapezoid(0,1,j)<<"\t\t   ||\t\t "<<simpson(0,1,j)<<"\t     \t ||      "<<M_PI/4<<"   ||"<<endl;
        



    };
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;

    
   
    return 0;
}