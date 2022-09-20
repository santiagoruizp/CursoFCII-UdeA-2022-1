
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include "EcEliptica.h"


// Función inhomogénea
double f(double ,double );
// Condición de frontera
double g(double ,double,double ,double,double ,double );
// Solución exacta
double u(double ,double );


int main(){
    
    // Número de pasos en x y y
    unsigned int n=100,m=100;
    // Fronteras de la región a solucionar
    double a=-2,b=2,c=0, d=4;

    EcEliptica Ejemplo1(a,b,c,d,n,m);
    int cond=Ejemplo1.GaussSeidel(&f,&g);

    if(cond==1){
      Ejemplo1.imprimir();
      //Ejemplo1.error(&u);
      Ejemplo1.guardar();
    }

    
  return 0;
}

// Función inhomogenea
double f(double x,double y){

 
    // Fluido en un punto de estancamiento
    return -2.0;
    
    // Problema 8
    //return -1.5/1.04;

    // Cargas positivas  
    //return -5*(exp(-1*(pow(x+1,2)/(2*0.1) + pow(y,2)/(2*0.1))) + exp(-1*(pow(x-1,2)/(2*0.1) + pow(y,2)/(2*0.1))));

    // Dipolo 
    //return (exp(-1*(pow(x+0.5,2)/(2*0.1) + pow(y,2)/(2*0.1))) - exp(-1*(pow(x-0.5,2)/(2*0.1) + pow(y,2)/(2*0.1))));

    // Ejemplo del libro
    //return x*exp(y);
}

// Función de frontera, se le ingresa a,b,c,d parámetros de frontera
double g(double x, double y,double a, double b, double c, double d){
    if(x==a){

        // Fluido en un punto de estancamiento
        return sinh(y);

        // Problema 8
        //return y*(5-y);

        // Dipolo, cargas positivas 
        //return 0;
        
        // Ejemplo del libro
        //return 0;
    }
    if(x==b){

        // Fluido en un punto de estancamiento
        return sinh(y);

         // Problema 8
        //return 0;

        // Dipolo, cargas positivas 
        //return 0;
        
        // Ejemplo del libro
        //return 2*exp(y);
    }
    if(y==c){

        // Fluido en un punto de estancamiento
        return -cosh(x)+cosh(2.0);
        
        // Problema 8
        //return x*(6.0-x);

        // Dipolo, cargas positivas 
        //return 0;

        // Ejemplo del libro
        //return x;
    }
    if(y==d){

        // Fluido en un punto de estancamiento
        return 27.2899;

        // Problema 8
        //return 0;

        // Dipolo, cargas positivas 
        //return 0;
        
        // Ejemplo del libro
        //return exp(1)*x;
    }
    return 0;
    
}

// Función solución
double u(double x, double y){

    // Fluido en un punto de estancamiento
    return 0;

    // Problema 8
    //return 0;

    // Cargas positivas
    //return (1/sqrt(pow(x-1,2) + pow(y,2)) + 1/sqrt(pow(x+1,2) + pow(y,2)))/(4.0*M_PI);

    // Dipolo
    //return (1/sqrt(pow(x-0.5,2) + pow(y,2)) - 1/sqrt(pow(x+0.5,2) + pow(y,2)))/(4.0*M_PI);

    // Ejemplo del libro
    //return x*exp(y);
}