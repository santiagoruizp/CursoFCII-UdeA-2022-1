#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void ascendenteorden( int * const, const int );

int main(){
    int tamanio = 0;
    cout<<"digite la longitud de la lista: \n ";
    cin >> tamanio;

    int a[tamanio];
    int elemento=0;
    cout<<"digite el arreglo\n";
    for ( int i = 0; i < tamanio; i++ ){
        cin >> elemento;
        a[i] = elemento;
        cout<<"ingrese el siguiente elemento: \n";
    }
    cout << "\n arreglo ingresado sin orden:\n";

    for ( int i = 0; i < tamanio; i++ ){
        cout << setw( 4 ) << a[i];
    }
    cout << "\n arreglo ordenado ascendentemente:\n";

    //ordenamiento ascendente
    int n = sizeof(a)/sizeof(a[0]);
    std::sort(a,a + n);
    for (int const &i: a) {
        std::cout << i << ' ';
    }

    int buscar=0;
    cout<<"\nIngrese el numero que desea buscar en el arreglo: ";
    cin>>buscar;

    int primero=0;
    int ultimo=tamanio-1;
    int medio=(primero+ultimo)/2;
    
    bool t = 1;
    while (t==1)
    {
        if (a[medio]== buscar) {
            cout<<" Se encontro el elemento:" << buscar <<" en la posición "<< medio+1<<endl;
            t = 0;
        } else if (a[medio]< buscar){
            primero=medio+1;
            } 

        else { ultimo = medio - 1;
        }
        medio = (primero+ultimo)/2;

        if (primero>ultimo){
        cout<<buscar<<"Ese elemento no esta en el arreglo";
        t = 0;}
    }

    return 0;
}