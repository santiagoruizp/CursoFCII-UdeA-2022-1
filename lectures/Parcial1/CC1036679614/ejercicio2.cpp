#include <iostream>
#include <list>
#include <iomanip>
#include<limits>
using namespace std;


//Función que permite determinar si un número es perfecto o no, se imprime el numero y sus divisores propios.
void perfecto(int n) {
    int contador = 1;
    list<int> divisores{ 1 };

    for (int i = 2; i < n; i++) {

        if (n % i == 0) {


            contador += i;
            divisores.push_back(i);
        }
    }
    if (contador == n) {
        cout << "El numero " << n << " es un numero perfecto:" << endl;
        cout << n << "= ";
        int c = 1;


        for (int x : divisores) {

            if (c < divisores.size())
                cout << setw(1) << x << " + ";
            else
                cout << setw(1) << x;
            c++;

        }

        cout << endl;

    }
}

int main() {
    int numero = 0;
    cout << "Ingrese hasta que número desea buscar números perfectos: " << endl;
    //Permite que solo se reciban valores numericos por teclado
    while (!(cin >> numero)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un valor numerico  " << endl;
    }

    for (int i = 2; i <= numero; i++) {
        perfecto(i);
    }
    return 0;
}