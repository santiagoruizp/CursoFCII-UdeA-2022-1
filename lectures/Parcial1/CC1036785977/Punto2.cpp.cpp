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
    {
        cout << x << " Es numero perfecto" << endl;
        cout << "Divisores:" << endl;
        for (int j=1 ; j<x ; j++)
        {
            if  ((x % j)==0)
                cout << j << endl;
        }
        cout <<" "<< endl;
        return 1; // Es perfecto
    }    
    else 
        return 0; // NO Es perfecto
}

// funcion main
int main()
{
    int iteraciones(100000); // hasta que numero se buscan los perfectos
    for (int k=1 ; k<=iteraciones ; k++)
    {
        perfecto(k);
    }
    return 0;
}

