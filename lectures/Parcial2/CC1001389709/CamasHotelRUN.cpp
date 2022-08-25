
#include<iostream>
#include<iomanip>

#include "CamasHotel.h"

using namespace std;


int main(){

    // Opciones para el usuario
    cout<<"Este programa procesa los datos de ocupación de camas de hotel a nivel regional de acuerdo a las siguientes opciones:"<<endl;
    cout<<"a: Leer y almacenar los datos."<<endl;
    cout<<"b: Crear lista de datos sin duplicados."<<endl;
    cout<<"c: Seleccionar datos de un hotel particular."<<endl;
    cout<<"d: Estadística por hotel."<<endl;
    cout<<"e: Ocupación de camas a la fecha."<<endl;
    cout<<"f: Eliminación de hotel de la base de datos."<<endl;
    cout<<"Cualquier otro caracter: Salir."<<endl;

    // Se solicita una opción
    cout<<endl<<"Ingrese opción: ";
    char option;
    cin>>option;

    // Se crea un objeto para el manejo de los datos
    ProcesoDatos archivo("camas_hotel.txt");

    // Mientras se solicite una de las opciones el programa no se cerrará
    while(option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == 'e' || option == 'f'){

        // Control para la ejecución de los casos 
        switch(option){

            case 'a':{
                // Se leen los datos y se cargan a la memoria
                archivo.leeProcesa();
                break;
            }
            case 'b':{
                archivo.nuevaListaSinDuplicados();
                break;
            }
            case 'c':{
                string selec;
                cout<<"Ingrese un código de hotel para obtener información: ";
                cin>>selec;
                archivo.seleccionar(selec);
                break;
            }






            case 'f':{
                string selec2;
                cout<<"Ingrese un código de hotel para eliminar de los datos: ";
                cin>>selec2;
                archivo.eliminarHotel(selec2);
                break;
            }




        }

        cout<<endl<<"Ingrese opción: ";
        cin>>option;

    }

  

}