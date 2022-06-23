#include <iostream>
#include<cmath>
using namespace std;
int main(){
  const float AIRCONV=8.7;
  const float PI=3.1415;
  float T_s, T_a;
  int op; 
  cout<<"\n Este programa calcula la tasa de transferencia de calor por convección de una superficie"<<endl;
  cout<<"\n Ingrese la temperatura de la superficie en [°C]"<<endl;
  cin>>T_s;
  cout<<"\n Ingrese la temperatura ambiente en [°C]"<<endl;
  cin>>T_a; 
  cout<<"\n si la forma de su superficie es: \n Rectangular ingrese 1 \n Elítica ingrese 2 \n Si tiene otra forma ingrese 3\n"<<endl;
  cin>>op;
  
switch(op){
  case 1:
  	float x,y;
  	cout<<"\n Ingrese el largo de su rectángulo en [m]"<<endl;
  	cin>>x;
  	cout<<"\n Ingrese el ancho de su rectángulo en  [m]"<<endl;
  	cin>>y;
  	cout<<"La tasa de transferencia de calor  es: \n"<< AIRCONV*x*y*(T_s-T_a)<<"[Watts/(m^2 °C)]"<<endl;
   	 break;
  case 2:
    	float a,b;
  	cout<<"\n Ingrese el eje menor de su elípse en [m] "<<endl;
  	cin>>a;
  	cout<<"\n  Ingrese el eje mayor  de su elípse en [m]  "<<endl;
  	cin>>b;
    	cout<<"La tasa de transferencia de calor es: \n"<< AIRCONV*a*b*PI*(T_s-T_a)<<"[Watts/(m^2 °C)]"<<endl;
   	 break;
   case 3:
      	 float A;
	 cout<<"Ingrese el área de su superficie en m^2"<<endl;
	 cin>>A;
	 cout<<"La tasa de transferencia de calor es: \n"<< AIRCONV*A*(T_s-T_a)<<"[Watts/(m^2 °C)]"<<endl;
    	 break;
  default:
    cout<<"Debe elegir alguna de las 3 opciones anteriores"<<endl;
  }
  return 0; 
}
/*Después de ejecutar el programa tenemos que:la tasa de tranferencia de calor de un chip rectángular de computador a 44°C hacia el medio que se encuentra a
44°C con  lados iguales de 2.0 \times 10^{-2} metros es: 0.01392[Watts/(m^2 °C)]

 */
