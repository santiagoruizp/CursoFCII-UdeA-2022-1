
#include "complejo.h"

using namespace std;

int main(){
   
   // Se crea un número complejo con entradas del usuario
   double a, b;
   
   cout<<endl<<"Creación de un número complejo."<<endl;
   cout<<"Ingrese la parte real: ";
   cin>>a;
   cout<<"Ingrese la parte compleja: ";
   cin>>b;   
   
   complejo n(a,b);
   
   // Se crea un número complejo con entradas del usuario
   double c, d;
   
   cout<<endl<<"Creación de un número complejo."<<endl;
   cout<<"Ingrese la parte real: ";
   cin>>c;
   cout<<"Ingrese la parte compleja: ";
   cin>>d; 
   
   complejo m(c,d);
   
   // Suma n+m
   cout<<endl<<"La suma es";
   n.SumaComplejos(n,m).ImpresiondeNumero();
   
   // Resta n-m
   cout<<endl<<"La resta es";
   n.RestaComplejos(n,m).ImpresiondeNumero();
   
   // Multiplicación
   cout<<endl<<"El producto es";
   n.ProductoComplejos(n,m).ImpresiondeNumero();
   
   // División
   cout<<endl<<"La división es";
   n.DivisionComplejos(n,m).ImpresiondeNumero();
   
   
   // Módulos
   double mod1 = n.Modulo(), mod2 = m.Modulo();
   cout<<endl<<"Los módulos son respectivamente "<<mod1<<" y "<<mod2<<endl;
   
   
   // Complejos conjugados
   cout<<endl<<"Los complejos conjugados son respectivamente "<<endl;
   n.Conjugado().ImpresiondeNumero();
   m.Conjugado().ImpresiondeNumero();
   
   return 0;
}
