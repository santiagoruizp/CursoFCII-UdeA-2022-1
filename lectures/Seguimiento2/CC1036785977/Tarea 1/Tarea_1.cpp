/*
Santiago Ruiz Piedrahita

Tarea 1
Busqueda binaria 
*/

#include <iostream>
#include <iomanip>
using namespace std;


void ordenamientoSeleccion( int * const, const int );
void intercambiar( int * const, int * const );

int main()
{
    cout<<"El programa realiza una Busqueda binaria en un arreglo\n"<<endl;
    int tam = 0;
    cout<<"Ingrese el tamaño del arreglo: ";
    cin >> tam;
    int Arreglo[tam];
    int num=0;
    cout<<"\nIngrese el arreglo (puede ser desordenado)\n";
    for ( int i = 0; i < tam; i++ ){
        cin >> num;
        Arreglo[i] = num;
    }
    
    cout << "\nArreglo desordenado:\n";

    for ( int i = 0; i < tam; i++ ){
        cout << setw( 4 ) << Arreglo[ i ];
    }
    
    ordenamientoSeleccion( Arreglo, tam ); // ordena el arreglo

    cout << "\nElementos de datos en orden ascendente\n";
    for ( int i = 0; i < tam; i++ ){
        cout << setw( 4 ) << Arreglo[ i ];
    }
  
    cout << endl;
    
    // Busqueda
    
    int bus=0;
    cout<<"\nIngrese el numero que desea buscar: ";
    cin>>bus;
    
    int primero=0;
    int ultimo=tam-1;
    int medio=(primero+ultimo)/2;
    
    bool x = 1;
    
    while (x==1)
    {
        if (Arreglo[medio]== bus) {
            cout<<" Se encontro el elemento " << bus <<" en la posición "<< medio+1<<endl;
            x = 0;
        
        }
        
        else if (Arreglo[medio]< bus){
            primero=medio+1;
        } 
        
        else {
            ultimo = medio - 1;
        }

        medio = (primero+ultimo)/2;
    
    
        if (primero>ultimo){
        cout<<bus<<" No se encuentra en el arreglo";
        x = 0;
    }
    }

    return 0;
}


void ordenamientoSeleccion( int * const arreglo, const int tamanio )
{
  int menor; 
  for ( int i = 0; i < tamanio - 1; i++ )
    {
      menor = i;
      
      for ( int subindice = i + 1; subindice < tamanio; subindice++ ){
	if ( arreglo[ subindice ] < arreglo[ menor ] ){
	  menor = subindice;
	}
      }
      intercambiar( &arreglo[ i ], &arreglo[ menor ] ); 
    } 
}

void intercambiar( int * const elemento1Ptr, int * const elemento2Ptr )
{
  int contenido = *elemento1Ptr;
  *elemento1Ptr = *elemento2Ptr;
  *elemento2Ptr = contenido;
}

