#include "BusquedaBinaria.h"

// función que aplica el método binario
void BusquedaBinaria(int num){
    cout<<num<<endl;
    int listOrd[100];
    int N=100;
    int a=0,b=N;

    // creamos la lista de números pares del 0 al 198
    for(size_t i{0}; i<N;++i){
        listOrd[i]=2*i;
    }
    // ahora aplicamos el método, donde a es el limite inferior y b el límite superior del array
    //conciderado, se disminuye b a la mitad para visualizar si esta en la mitad superior o la mitad inferior 
    // del array num.
    b/=2;
    // se para cuando b-a sea menor a 2, ya que al ser enteros no se pueden acercar más que 1
    while(abs(a-b)>=2){
        // h es la mitad del ancho del sub array
        int h=(b-a)/2;
        // se evalua si el num esta en el extremos inferior
        if(listOrd[b]>num){
        b-=h;// si es así b, se disminuye en h para obtener la mitad del array inferior
        }else{
        // si no, a se aumenta en 2 y b en h para tomar del array superior la parte inferior
        a+=2*h;
        b+=h;
        }
        // se observa si se encontro el número en a o en b
        if(listOrd[b]==num){
        cout << "La posición del número es:"<<b<<endl;
        break;
        }
        if(listOrd[a]==num){
        cout << "La posición del número es:"<<a<<endl;
        break;
        }
        // si a-b es 1, y ni a ni b es el número, significa que no esta en la lista
        if(abs(a-b)==1)
        cout << "El número no se encuentra dentro de la lista"<<endl;
    };
}