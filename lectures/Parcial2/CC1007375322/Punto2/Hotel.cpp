//leer datos de un archivo
#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>
#include <iomanip>
#include <string>

#include "Hotel.h"

using namespace std;

// contructor de clase, solo se recibe el nombre del archivo y se ejecuta leeProcesa
DatosHotel::DatosHotel(const string NameArchivo ){
  Name=NameArchivo;
  leeProcesa();
}
// función leeProcesa
void DatosHotel::leeProcesa(){
  //lee archivo
  ifstream archivo( Name );
  //verifica que se lea correctamente
  if ( archivo.fail() )   
  {
    cout << "No se pudo abrir el archivo" << endl;
    exit( 1 );
  }
  string list;
  cout << left << "Fecha "<< "Codigo Hotel" << " Numero de habitacion" << endl << fixed << showpoint;
  // muestra cada registro en el archivo
  archivo>>list;// se salta el primer termino que son los keys del archivo
  while ( archivo >> list ){
    cout << imprimir(list)<<endl;
    FileCompleto.push_back(list);//agrega cada fila a la lista
  }
}
//función que permite borrar duplicados
void DatosHotel::nuevaListaSinDuplicados(){
  int i=0;
  // se llena File inicialmente con todos los elementos
  File=FileCompleto;
  // se imprime el nuevo archivo sin elementos repetidos
  cout << left << "Fecha "<< "Codigo Hotel" << " Numero de habitacion" << endl << fixed << showpoint;
  // se recorre dos veces sobre el archivo para poder comparar elemento con elemento
  for(string element: File){
    int k=0;
    for(string element2: File){
      // se verifica que no sea el mismo elemento y que coincidan, para identificar que el elemento esta duplicado
      if(element==element2 && i!=k){
        File.erase(File.begin()+k);// se elimina elemento duplicado
      }
      k++;
    }
    i++;
    // se imprimen elementos no duplicados
    cout << imprimir(element)<<endl;
    
  };
};

// función que nos permite imprimir cada fila sin los ; y separados correctamente
string DatosHotel::imprimir(const string element){
  string elementSeparado;
  int start = 0;
  // se encuentra cada punto y coma y se corta ahí el string y se añade un espacio en blanco de 5 space
  int end = element.find(";");
  while (end != -1) {
    elementSeparado+= element.substr(start, end - start) +"     ";
        start = end + 1;
        end = element.find(";", start);
    }
  elementSeparado+=element.substr(start, end - start);
  return elementSeparado;// se retorna elemento a imprimir correctamente

}
// función que permite seleccionar camas de un hotel referido, se introduce el codigo del hotel
vector <string> DatosHotel::seleccionar(const string codhot){
  cout<<"Camas en el hotel "<<codhot<<endl;
  // se añaden los ; de los lados del codigo del hotel para facilitar la busqueda
  string codhotsep=";"+codhot+";";
  vector <string> listcama;
  for(string element: File){
    // se busca si el codigo del hotel se encuentra en el elemento
      int cond=element.find(codhotsep);
      // si se encuentra se sustrae el número de la cama y se guarda en listcama
      if(cond<File.size() && cond>0){
        string cama=element.substr(cond+codhotsep.size(),element.size());
        listcama.push_back(cama);
        cout<<cama<<endl;// se imprime la cama correspondiente
      };
  }
  return listcama;// se devuelve el vector con las camas correspondientes al hotel
}
// función estadistico, muestra el número de camas por hotel
void DatosHotel::estadistico(){
  string cond="",cod;// cond nos permite identificar si el codigo del hotel ya aparecio una primera vez
  int star;
  int k;
  // se recorre sobre el archivo
  for(string element: File){
    star=element.find(";");
    cod=element.substr(star+1,2);// se substra el codigo del hotel
    if(cond.find(cod)>cond.size()){// se verifica si el codigo ya aparecio o es la primera vez, para buscar la cantidad de veces que aparece en File
        cond+=cod;
        k=0;
        // se recorre File nuevamente buscando cuantas veces esta el codhotel en el archivo
        for(string element2:File){
          // si coincide los codigos se suma una cama
            if(cod==element2.substr(star+1,2)){
              k+=1;
            }
        }
        // se muestra el número de camas para el hotel conciderado
        cout<<"Hotel "<<cod<<" tiene en total "<<k<<" cama(s) distintas"<<endl;
    }
    
  };

};

// función contar
void DatosHotel::contar(const string fecha){
  int k=0;
  // se recorre sobre los elementos del archivo
  if(fecha.size()==8){
  for(string element: File){
    // se observa si la fecha introducida coincide con el elemento, si coincide se añade 1 
    if(fecha==element.substr(0,fecha.size())){
      k+=1;
    }
  }
  cout<<"La cantidad de camas ocupadas la fecha "<<fecha<<" es de "<<k<<endl;}
  else cout<<"Ingrese una fecha correcta"<<endl;
}
//función eliminar hotel
void DatosHotel::eliminarHotel(const string hotel){
  int k=0;
  int star;
  cout<<"Se eliminan todas las ocurencias del hotel "<<hotel<<endl;
  cout << left << "Fecha "<< "Codigo Hotel" << " Numero de habitacion" << endl << fixed << showpoint;
  // se recorre sobre las filas del archivo
  for(string element: File){
    star=element.find(";");
    if(hotel==element.substr(star+1,2)){// si el identificador del hotel coincide con el buscado, se entra y se elimina del archivo
        File.erase(File.begin()+k);
     }else{
      // se imprimen solo los elementos no eliminados
      cout << imprimir(element)<<endl;
     };
      k++;
  }
  
}