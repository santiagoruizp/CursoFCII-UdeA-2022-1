#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int vector[10]={1,2,4,5,6,7,8,9,10}; // No contiene el 3 para verificar que funciona correctamente
    int inMax=10; //inicializa con el tamaño del arreglo
    int inMin=0;
    int media=(inMin + inMax)/2;
    int numBuscar;
    bool enc=true;
    cout<<"Ingrese un valor para su busqueda: ";
    cin>>numBuscar;

    while (enc)
    {
        // La busqueda se realiza respecto a la posicion
        if (numBuscar==vector[media]) // En caso que el valor corresponda a la posicion en media
            {
                cout<<"Numero encontrado! El numero es: "<<numBuscar
                    <<" y se encuentra en la posicion "<<media+1;
                enc=false;                
            }        

        if (numBuscar<vector[media]) //Coteja valor buscado con el elemento de la lista correspodiente media 
            inMax=media;                
        else
            inMin=media;

        if (inMax==(media+1) && numBuscar!=vector[media]) // en caso que el valor no se encuentre en la lista
            {
                cout<<"El valor no se encuentra en la lista"<<endl;
                enc=false;
            }                    

        media=(inMin + inMax)/2;        
    }    

    return 0;
}

