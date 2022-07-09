// La ley de transferencia de calor nos indica que q=hA(Ts-Ta)
//Inicialmente se le pide al usuario Ts y Ta y posteriormente se pregunta por el tipo de Área considerada y sus dimensiones.

#include <iostream>

using namespace std;

int main(){

  float Ta,Ts,A,q,h,w,a,b;
  int i;
  const float AIRCONV=8.7;
  const float PI  = 3.1416;
  cout<<"Introduzca la temperatura de la superficie en C°: "<<endl;
  cin>>Ts;
  cout<<"Introduzca la temperatura del ambiente en C°: "<<endl;
  cin>>Ta;
  cout<<"Introduzca el número correspondiente al área a conciderar \n 1. Área de un rectángulo \n 2. Área de una elipce \n 3. Otra"<<endl;
  cin>>i;
  switch(i)
    {
    case 1:
      cout << "Ingrese el ancho del rectángulo en m: "<<endl;
      cin>> w;
      cout << "Ingrese la altura del rectángulo en m: "<<endl;
      cin>>h;
      A=w*h;
      break;
    case 2:
      cout << "Ingrese el eje mayor de la elipse en m: "<<endl;
      cin>> a;
      cout << "Ingrese el eje menor de la elipse en m: "<<endl;
      cin>> b;
      A=PI*a*b;
      break;
    case 3:
      cout << "Ingrese el area de la superficie en m^2:"<<endl;
      cin>>A;
      break;
    default:
      cout<< "Ingreso una opción incorrecta"<<endl;
      A=0;
      break; 
    };
  
  q=AIRCONV*A*(Ts-Ta);
  cout << "La razón de transferencia de calor es: "<< q<<"W/(m^2°C)"<<endl;

  return 0;
  
}
