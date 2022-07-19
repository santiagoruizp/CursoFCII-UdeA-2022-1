#include<iostream>
#include<cmath>
using namespace std;
float f(float x) //definimos la función que queremos integrar
{
  return (log(x));
}
//////////////////////
int main(){
float a;
float b;
int n;
cout<<"Este programa calcula la integral de la función ln(x)"<<endl;
cout<<"\nIngrese el inicio del intervalo de integración"<<endl;
cin>>a;
cout<<"Ingrese el final del intervalo de integración"<<endl;
cin>>b;
cout<<"Ingrese en cuántos rectángulos quiere dividir el área que quiere hallar"<<endl;
cin>>n;
float h=((b-a)/n);   //ancho de los intervalos en los que dividimos el intervalo entre a y b. 
////////////////////////////////////////////////////////////////////////////////////////////////////// ACÁ DE IMPLEMENTA LA REGLA DE LOS TRAPECIOS. 
float suma=(1/2)*(f(a)+f(b));
for(int c=1;c<=n;c++){
 suma+=f(a+c*h);
}
float trap=h*suma;
////////////////////////////////////////////////////////////////////////////////////////////////// ACÁ SE IMPLEMENTA LA REGLA DE SIMPSON, TOMADO DEL BURDEN
float S1=0;
float S2=0;
for(int c=1;c<=n;c++){
	if (c%2==0){
	S2 += f(a + c*h);
	}
	else{
	S1 += f(a + c*h);
	}
}
float simp=(f(a) + f(b) +2*S2 + 4*S1)*h/3;
/////////////////////////////////////////////////////////////////////////////////////////////// ENTREGAMOS EL RESULTADO
cout<<"La integral con la regla de los trapecios es: "<<trap<<endl;
cout<<"La integral con la regla de Simpson es: "<<simp<<endl;
return 0;
}
