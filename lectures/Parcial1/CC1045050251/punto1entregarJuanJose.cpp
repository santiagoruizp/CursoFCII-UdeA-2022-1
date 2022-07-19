#include<iostream>
#include<cmath>
using namespace std;

float funcion(float x){
    return x*x;
}

double metodoSimpson(float limitea, float limiteb, int intervalos){
    float paso = (limiteb - limitea)/intervalos;
    
    float f2=0,f3=0;

    for(int i=1; i<intervalos;i++){
        float variable= limitea+i*paso;
        if (i%2==0){
            f2 = f2+ funcion(variable);    
        }
        else{
            f3 = f3+funcion(variable);
        }
    } 

    double integralSimpson = paso*(funcion(limitea)+funcion(limiteb)+2*f2+4*f3)/3;
    return integralSimpson;
}

double trapezoide(float limitea, float limiteb, int intervalos){

    float paso = (limiteb - limitea)/intervalos;
    float f2=0;

    for(int i=1; i<intervalos;i++){
        float variable = limitea + i*paso;
        f2 += funcion(variable);        
    }

    double integraltrapezoide = paso*(funcion(limitea)+funcion(limiteb)+2*f2);
    
    return integraltrapezoide;
}

int main(){
    float limitea,limiteb;
    int intervalos;
    cout << "Ingrese el limite inferior ";
    cin>>limitea;
    cout << "Ingrese el limite superior ";
    cin>>limiteb; 
    cout << "Ingrese la cantidad de intervalos:";
    cin>>intervalos;

    cout << "La integral con Simpson es " << metodoSimpson(limitea,limiteb,intervalos) << endl;
    cout << "La integral con Trapezoidal es " <<trapezoide(limitea, limiteb, intervalos)<< endl;
    return 0;
}