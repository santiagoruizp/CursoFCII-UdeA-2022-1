#include "turismo.h"
using namespace std;

int main()
{
  Turismo prueba( "camas_hotel.txt" );
  string seleccion = "";
  while (seleccion != "g"){
    cout << "a. Inicializar archivo " << endl;
    cout << "b. Crear lista sin duplicados" << endl;
    cout << "c. Crear lista de camas de un hotel" << endl;
    cout << "d. Mostrar estadisticas de numero de camas por hotel" << endl;
    cout << "e. Cantidad de camas ocupadas por fecha especificada" << endl;
    cout << "f. Eliminar registro de un hotel" << endl;
    cout << "g. Salir" << endl;
    cout << "\nSeleccione una opcion: " << endl;
    cin >> seleccion;
    
    if (seleccion == "a"){
      cout<<"Bienvenido a la secretaria de Turismo."<<endl;
      cout<<"Estos son los datos que se cargaron"<<endl;
      prueba.leeProcesa (prueba.getName());
      cout<<endl;
    }
    
    if (seleccion == "b"){
      cout<<"Esta es la lista sin duplicados: "<<endl;
      prueba.nuevaListaSinDuplicados();
      cout<<endl;
    }
    
    if (seleccion == "c"){
      int codigo;
      cout<<"Se creara una lista con los datos de las camas de un hotel"<<endl;
      cout << "Ingresa el codigo de hotel: " << endl;
      cin >> codigo;
      prueba.seleccionar(codigo);
      cout<<endl;
    }
    
    if (seleccion == "d"){
      cout<<"Se muestran la cantidad de camas por hotel"<<endl;
      prueba.estadistico();
      cout<<endl;
    }
        
    if (seleccion == "e"){
      cout<<"Ingrese una fecha y se obtiene la cantidad de camas ocupadas en dicha fecha"<<endl;
      int aa, mm, dd;
      cout << "Ingresa el dia: " << endl;
      cin >> dd;
      cout << "Ingresa el mes: " << endl;
      cin >> mm;
      cout << "Ingresa el año: " << endl;
      cin >> aa;
      prueba.contar(dd,mm,aa);
      cout<<endl;
    }
        
    if (seleccion == "f"){
      cout<<"Se elimina los datos de un hotel elegido"<<endl;
      int codigo;
      cout << "Ingresa el codigo del hotel para eliminar: " << endl;
      cin >> codigo;
      prueba.eliminarHotel(codigo);
    }
  }
return 0;
}
