#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Hotel.h"

using namespace std;


int main()
{
    Hotel hotel("camas_hotel.txt");

    int opc=1;

    while(opc<7 && opc>0){

        cout << "Bienvenido. " << endl;
        cout << "1: leeProcesa (muestra lista del archivo)" << endl;
        cout << "2: nuevaListaSinDuplicados (muestra lista del programa)" << endl;
        cout << "3: seleccionar (muestra datos de 1 hotel)" << endl;
        cout << "4: estadistico (muestra habitaciones por hotel)" << endl;
        cout << "5: contar (camas ocupadas una fecha dada)" << endl;
        cout << "6: eliminarHotel"<< endl;
        cout << "7: Salir" << endl;
        cout << "Ingrese el número correspondiente a la opción que desea acceder: " << endl;

        cin >> opc;
        string codigoHotel;
        string fecha;
        vector<vector<string>> hotelSeleccionar;


        switch (opc)
        {
            case 1:
                cout << "LeeProcesa"  << "\n" <<endl;
                hotel.leeProcesa();
                hotel.imprimirDatosArchivo();
                cout << "\n";
                break;
            case 2:
                cout << "nuevaListaSinDuplicados"<< "\n" << endl;
                hotel.nuevaListaSinDuplicados();
                hotel.imprimirDatosPrograma();
                cout << "\n";
                break;
            case 3:
                cout << "Ingrese el código del hotel: " << endl;
                cin >> codigoHotel;
                hotelSeleccionar = hotel.seleccionar(codigoHotel);
                cout << "\n";
                cout << "Los datos del hotel "<< codigoHotel << " son: "<< endl;
                for(vector<string> i: hotelSeleccionar){
                    cout << i[0] << " " <<  i[1]  <<  " " << i[2]<< endl;
                }
                cout << "\n";
                break;
            case 4:
                hotel.estadistico();
                break;
            case 5:
                cout << "Ingerese la fecha para la cual desea averiguar la cantidad de camas ocupadas en el formato aaaammdd: " << endl;
                cin >> fecha;
                hotel.contar(fecha);
                break;
            case 6:
                cout << "Ingerese el hotel que desea eliminar: " << endl;
                cin >> codigoHotel;
                hotel.eliminarHotel(codigoHotel);
                break;
            case 7:
                cout << "Cerrando el programa" << endl;
                break;
            default:
                cout << "Ingereso otra opción diferente a las posibles, se finaliza el programa." << endl;
        };

    };

    return 0;
}

