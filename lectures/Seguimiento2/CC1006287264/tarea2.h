#include <string>
#include<iostream>
using namespace std;

class convertircadenas
{
private:
  string nombreCadena;
  string nombreCadena2;    
public:
  // constantes
  //const static int estudiantes = 10; // numero de estudiantes
  //const static int pruebas = 3; // número de pruebas
   
  convertircadenas()
    {
        cout<<"Enter firt text:";
        cin>>nombreCadena;
        cout<<"Enter second text:";
        cin>>nombreCadena2;
        
    }
  void establecerNombreCadenas( string ,string );
  string obtenerNombreCadenas(); 
  void mostrarMensaje();
  
  
  void comparar();
  string Vocales(string& str );
  string Consonantes(string& str);
  string reverse(string sr);
  string concatenadas();
  void Recibircadenas();
  

  //string convert_consonants(string);
  
  //void procesarCalificaciones();
  //int obtenerMinimo(); // 
  //int obtenerMaximo(); //
  //double obtenerPromedio( const int [], const int ); 
  //void imprimirGraficoBarras(); 
  //void imprimirCalificaciones();
  
 
  //arreglo bidimensional de estudiantes
};