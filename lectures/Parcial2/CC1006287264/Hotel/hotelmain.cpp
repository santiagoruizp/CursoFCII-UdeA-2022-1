#include "hotel.h"
using namespace std;

int main()
{
  Turismo prueba( "camas_hotel.txt" );
  string seleccion = "";
  ifstream infile;
  vector<string> a; 
  //prueba.leeProcesa(infile,prueba.getName());
  
  //prueba.nuevaListaSinDuplicados(prueba.getleeProcesa());
  //prueba.seleccionar(prueba.getnuevalista());
  
  //prueba.estadistico(prueba.getnuevalista());
  //prueba.contar(prueba.getnuevalista());
  
  
  
  
  //prueba.getleeProcesa();
  //string namefile = "camas_hotel.txt";
  
  while (seleccion != "g"){
    cout << "a. Inicializar archivo " << endl;
    cout << "b. Crear lista sin duplicados" << endl;
    cout << "c. Crear lista de camas de un hotel" << endl;
    cout << "d. Mostrar estadisticas " << endl;
    cout << "e. Cantidad de camas ocupadas por fecha especificada" << endl;
    
    cout << "g. Salir" << endl;
    cout << "\nSeleccione una opcion: " << endl;
    cin >> seleccion;
    
    if (seleccion == "a"){
      cout<<"Bienvenido a la secretaria de Turismo."<<endl;
      cout<<"Estos son los datos que se cargaron"<<endl;
      prueba.leeProcesa (infile,prueba.getName());
    
      cout<<endl;
    }
    
    if (seleccion == "b"){
      cout<<"Lista sin duplicados: "<<endl;
      prueba.nuevaListaSinDuplicados(prueba.getleeProcesa());
      cout<<endl;
    }
    
    if (seleccion == "c"){
      cout<<"Lista con los datos de las camas de un hotel"<<endl;
      prueba.seleccionar(prueba.getnuevalista());
      cout<<endl;
    }
    
        
    if (seleccion == "d"){
      cout<<"Cantidad de camas por hotel"<<endl;
      prueba.estadistico(prueba.getnuevalista());
      cout<<endl; 
      }
    if (seleccion == "e"){

      prueba.contar(prueba.getnuevalista());
      cout<<endl;
    }



    
     }
     
return 0;
}