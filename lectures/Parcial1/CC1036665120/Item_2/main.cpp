/*

Se dice que un número entero es un número perfecto si la suma de sus divisores, 
incluyendo 1 (pero no el número en sí), es igual al número. Por ejemplo, 6 es un número 
perfecto ya que 6 = 1 + 2 + 3. Escriba una función llamada perfecto que determine si el 
parámetro numero es un número perfecto. Use esta función en un programa que determine e 
imprima todos los números perfectos entre 1 y 1000. Imprima los divisores de cada número 
perfecto para confirmar que el número sea realmente perfecto. Ponga a prueba el poder de su 
computadora, evaluando números mucho más grandes que 1000.

*/




#include <iostream>
#include <list>
#include <tuple>

using namespace std;


// ---------------------------------------
list<int> divisores(int numero){

    // ---------------------------------------------------------
    // Retorna una lista con los divisores del número ingresado 
    // ---------------------------------------------------------

    // Encontrar los Divisores:
    // Recorre todos los números hasta el número ingresado, para encontrar cuando 
    // el residuo se hace 0 en la división

    list<int> _divisoresList;

    for (int i = 1; i < numero; i++)
    {
        if (numero%i==0.0)
        {
            // Si el residuo es cero, es decir, es un divisor, entonces se agrega a la lista
            _divisoresList.push_back(i);
        }
        
    }

    return _divisoresList;
}


// ---------------------------------------
int sumDivisores(list<int> lista){

    // ---------------------------------------------------------
    // Retorna un entero con la suma de los valores de la lista
    // ---------------------------------------------------------

    // Longitud de la lista
    int sizeList = lista.size();

    // La suma de los elementos de la lista es la suma de los 
    // divisores de un número dado
    int suma = 0;
    list<int>::iterator it;

    for (it=lista.begin(); it!=lista.end(); it++)
    {
        suma += *it;
    }

    return suma;
}


// ---------------------------------------
void perfecto(int numero){

    // Lista de divisores de 'numero'
    list<int> divisoresList = divisores(numero);
    // cout << "numero: " << numero;

    // Suma de los divisores de 'numero' y la cantidad de divisores
    int sumaDiv = sumDivisores(divisoresList);
    //cout << " sumaDiv: " << sumaDiv << " sizeList: " << cantidadDiv << ", --> ";

    list<int>::iterator it;

    if (sumaDiv == numero){

        // begin(): It returns the iterator to the first element in the list.
        // end(): It returns the iterator pointing to the theoretical last element, 
        // which follows the last element.

        cout << "Número perfecto: " << numero << endl;

        for (it=divisoresList.begin(); it!=divisoresList.end(); it++)
        {
             // Busca el último elemento de la lista e imprime la igualdad  
            if (*it==divisoresList.back())
            {
                cout << *it << " = " << numero << endl;

            }else{
                // va imprimiendo los divisores 
                cout << *it << " + ";
            }
            
            
        }
    }
    
}



int main(){

    int numIngresar;
    cout << "------------------------------------" << endl;
    cout << "PROGRAMA QUE BUSCA NÚMEROS PERFECTOS" << endl;
    cout << "------------------------------------" << endl;
    cout << "Rango de Búsqueda --> Ingrese el número entero hasta donde se buscará:  ";
    cin >> numIngresar;

    for (int i = 1; i <= numIngresar; i++)
    {
        perfecto(i);
    }
    
    return 0;
}


