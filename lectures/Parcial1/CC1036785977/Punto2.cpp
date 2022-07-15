/*
Santiago Ruiz Piedrahita
Parcial #1 
Punto #2
*/
#include <iostream>

using namespace std;

// Definimos la funcion numero perfecto

int perfecto(int x)

{
    int suma = 0;
    
    for (int i=1 ; i<x ; i++)
    {
        if  ((x % i)==0)
            suma += i;
        
    }
    
    if (suma==x) 
        return 1; // Es perfecto
        
    else 
        return 0; // NO Es perfecto
}

// funcion main
int main()
{
    int iteraciones(100000); // hasta que numero se buscan los perfectos
    for (int j=1 ; j<=iteraciones ; j++)
    {
        if (perfecto(j)==1)
        {
            cout << j << " Es numero perfecto" << endl;
            cout << "Divisores:" << endl;
            for (int i=1 ; i<j ; i++)
            {
                if  ((j % i)==0)
                    cout << i << endl;
                    
            }
            cout <<" "<< endl;
        }
        
    }
    return 0;
}

