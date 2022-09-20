
#include <iostream>
using namespace std;

#include "Hotel.h"

int main()
{   
    // se crea el objeto con el archivo camas_hotel.txt a usar
    DatosHotel hotel("../../camas_hotel.txt");
    // se ejecuta nuevaListaSinDuplicados ya que esta es necesaria para las opciones de la 3 en adelante, por tanto el archivo debe existir 
    // en caso de que el usuario llame primero a una de estas funciones
    hotel.nuevaListaSinDuplicados();
    int opc=1;
    // se ejcuta la lista de opciones acorde a lo pedido en el punto, si se elije opción 7 u otra no existente, acaba el programa
    while(opc<7 && opc>0){
    cout<<"Bienvenido al sistema de datos de hotel: \n 1) leeProcesa \n 2)nuevaListaSinDuplicados\n 3) seleccionar"<<endl;
    cout<<"4) estadistico \n 5) contar \n 6) eliminarHotel \n 7) salir \n Ingrese el número correspondinete a la opción que desea acceder: "<<endl;
    cin>>opc;
    string codhot;
    string fecha;
    switch (opc)
    {
    case 1:
        cout<<"Se ejecuta la función LeeProcesa"<<endl;
        hotel.leeProcesa();
        break;
    case 2:
        cout<<"Se ejecuta la función nuevaListaSinDuplicados"<<endl;
        hotel.nuevaListaSinDuplicados();
        break;
    case 3:
        cout<<"Ingrese el código del hotel:"<<endl;
        cin>> codhot;
        hotel.seleccionar(codhot);
        break;
    case 4:
        cout<<"La cantidad de camas registradas por hotel es:"<<endl;
        hotel.estadistico();
        break;
    case 5:
        cout<<"Ingerese la fecha para la cual desea averiguar la cantidad de camas ocupadas en el formato aaaammdd: "<<endl;
        cin>>fecha;
        hotel.contar(fecha);
        break;
    case 6:
        cout<<"Ingerese el hotel que desea eliminar: "<<endl;
        cin>>codhot;
        hotel.eliminarHotel(codhot);
        break;
    case 7:
        cout<<"Fin del programa"<<endl;
        break;
    default:
        cout<<"Ingereso otra opción diferente a las posibles, se finaliza el programa."<<endl;
    };

    };
    return 0;
};

