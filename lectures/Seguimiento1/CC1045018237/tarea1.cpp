#include<iostream>
int main ()
{
  float q=0;
  float h=0;
  float A=0;
  float Ts=0;
  float Ta=0;

  std::cout <<"Escriba la temperatura superficial en centigrados";
  std::cin >>Ts;
  std::cout <<"Escriba la temperatura ambiente en centigrados";
  std::cin>>Ta;
  std::cout <<"Escriba el area en metros cuadrados";
  std::cin>>A;
  std::cout <<"Escriba el coeficiente de transferencia de calor en watts sobre metros cuadrados centigrados";
  std::cin>>h;

  q=h*A*(Ts-Ta);

  std::cout <<"la transferencia de calor es" << q << std::endl;

}


  
