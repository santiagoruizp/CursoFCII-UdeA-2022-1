#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
using namespace std; 

class Exponencial{
    private: //declaracion de clase

        float x; //declaracion de variables         
        int N; 

    public: // funciones

        Exponencial(int, float);// funcion constructora
        float factorial(int);
        float expansion(int,float);
        float resultado(float);
};

//implementacion de clase

Exponencial::Exponencial(int N, float x){ //funcion constructora
    
    factorial(N);
    expansion(N, x);
}

float Exponencial::factorial(int K){
	 return tgamma(K + 1); 
}

float Exponencial::expansion(int N, float x){ 
    float sumatoria=0;
    for (int c=0;c<=N;c++){
        sumatoria+=(pow(x,c))/(factorial(c));
    }

    return sumatoria;
}


int main(){

    float x; int N; float U; //declaracion de variables

    cout<<"Ingrese el número x para calcular su exponencial"<<endl;
    cin>>x;
    cout<<"Ingrese N para la cantidad de terminos de precision"<<endl;
    cin>>N;
    Exponencial exponencial1(N,x);
    cout<< "el factorial del numero N es:" << exponencial1.factorial(N) <<endl;
    cout<< "La sumatoria de la expansion e**x es:" <<exponencial1.expansion(N,x) <<endl;
    return 0; 
}


