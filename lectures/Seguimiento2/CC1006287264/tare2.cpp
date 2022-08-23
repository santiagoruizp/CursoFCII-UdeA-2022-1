#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include "tarea2.h"

using namespace std;

// el constructor inicializa nombreCurso y el arreglo calificaciones

void convertircadenas::establecerNombreCadenas( string cadena1,string cadena2)
{
//nombreCurso = cadena1; 
//nombreCurso2= cadena2;
} 

string convertircadenas::obtenerNombreCadenas()
{
return "Cadena1: "+nombreCadena + "\n" +"Cadena2: "+nombreCadena2 ; 
//cout << nombreCurso << '\n' << nombreCurso2 << endl;

} 

void convertircadenas::mostrarMensaje()
{
cout << "Bienvenido\n" << obtenerNombreCadenas() << "!" << endl;
}

void convertircadenas::comparar( )
{ 
  
  //nombreCurso= cad1;
  //nombreCurso2= cad2;
  int resultado{nombreCadena.compare( nombreCadena2)};

  if ( resultado == 0 )
    cout << "cadena1.compare( cadena2 ) == 0\n";
  else{
    if (resultado > 0 )
      cout << "cadena1.compare( cadena2 ) > 0\n";
    else // resultado < 0
      cout << "cadena1.compare( cadena2 ) < 0\n";
   }
}
string convertircadenas::Vocales(string& str)
{
    // Stores the length
    // of str
    
    int N = str.length();
    
 
    for (int i = 0; i < N; i++) {
        if (str[i] == 'a' || str[i] == 'e'
            || str[i] == 'i' || str[i] == 'o'
            || str[i] == 'u') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    return str;
}
string convertircadenas::Consonantes(string& s)
{   
    for (int i=0; i< s.length();i++ ){
    if (!(s[i] == 'a' || s[i] == 'e'
            || s[i] == 'i' || s[i] == 'o'
            || s[i] == 'u') )
   {
    s[i]= toupper(s[i]);
    }
  }
    return s;
}
string convertircadenas::reverse(string sr)
{
    int n = sr.length();
 

    for (int i = 0; i < n / 2; i++)
        {swap(sr[i], sr[n - i - 1]);
        }
    return sr;
} 
string convertircadenas::concatenadas()
{
   return Vocales(nombreCadena) + " " + Consonantes(nombreCadena2);
}

void convertircadenas::Recibircadenas()
{
    cout <<obtenerNombreCadenas()<<"\n"
    << "Cadena1 con vocales mayusculas:"<<" "<< Vocales(nombreCadena)<<"\n"
    <<  "Cadena2 y sus consonantes mayusculas:"<< Consonantes(nombreCadena2)<<"\n" 
    << "Concatenadas: "<< Vocales(nombreCadena) + " " + Consonantes(nombreCadena2)<<"\n"
    <<"Invertida: "  << reverse(concatenadas() )    <<endl;
    
   // cout<< Consonantes(nombreCurso2)<<endl;
}

