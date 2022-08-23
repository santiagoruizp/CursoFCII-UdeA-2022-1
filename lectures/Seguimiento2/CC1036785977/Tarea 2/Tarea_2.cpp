/*
Santiago Ruiz Piedrahita

Tarea2

Escribir una funcion, "RecibirCadenas",  que recibe como parametros dos cadenas que puede contener espacios, la funcion deberá:

    Decir qué cadena es mayor y cuál es menor alfabéticamente
    Generar una nueva cadena que será la primera cadena leída, con las vocales convertidas a MAYÚSCULAS
    Generar una nueva cadena que será la segunda cadena leída, con las consonantes convertidas a MAYÚSCULAS
    Generar una nueva cadena concatenando las dos que ya fueron convertidas
    Generar una nueva cadena que contenga la cadena concatenada invertida

Incluya la función "RecibirCadenas"  en un programa ejecutable en C++, y use el programa para pedir al usuario que introduzca las dos cadenas con las que probara su función.

Al finalizar el programa, este deberá:
    Imprimir las dos cadenas originales
    Imprimir las dos cadenas con las conversiones
    Imprimir la cadena concatenada
    Imprimir la cadena concatenada invertida*/
    
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype> 

using namespace std;

void RecibirCadenas(const char* s1,const char* s2);
void convertirAMayusculasVocales( char *s );
void convertirAMayusculasConsonantes( char *s );

int main()
{
  // Tamaños de las cadenas
  int Ts1;
  int Ts2;
  cout << "Ingrese el tamaño de la cadena 1 y la 2 respectivamente: "<< endl;
  cin >> Ts1 >> Ts2;
  
  // se preguntan las cadenas
  char s1[Ts1]=""; 
  char s2[Ts2]="";
  
  cout<<"Ingrese la cadena #1: ";
  cin.ignore();
  cin.getline (s1,Ts1);

  cout<<"Ingrese la cadena #2: ";
  cin.getline (s2,Ts2);

  RecibirCadenas(s1,s2); 
  
 return 0; 
}   


void RecibirCadenas(const char* s1,const char* s2){
    
  int tam = strlen( s1 ) + strlen( s2 );
  // Imprime las 2 cadenas
  cout << "\nLa cadena #1 es: " << s1 << "\nLa cadena #2 es: "<< s2;
  
  // compara
  if (strcmp( s1, s2 )==0){
    cout << "\nLas cadenas son iguales\n"<<endl;}
  else if (strcmp( s1, s2 )<0){
    cout << "\nLa cadena #1 es menor que la cadena #2\n"<<endl;}
  else if (strcmp( s1, s2 )>0){
    cout << "\nLa cadena #1 es mayor que la cadena #2\n"<<endl;}
  
  // primera cadena leída, con las vocales convertidas a MAYÚSCULAS; s1 -> s3
  
  char s3[tam] ;
  strcpy( s3, s1 );
  convertirAMayusculasVocales(s3);

  cout << "La cadena #3 que es la cadena #1 con las vocales en mayúsculas es: "<<endl;
  cout << "Cadena #1: "<<s1<<endl;
  cout << "Cadena #3: "<<s3<<endl;
  
  // segunda cadena leída, con las consonantes convertidas a MAYÚSCULAS s2 -> s4
  char s4[tam] ;
  strcpy( s4, s2 );
  convertirAMayusculasConsonantes(s4);

  cout << "\nLa cadena #4 que es la cadena #2 con las consonantes en mayúsculas es: "<<endl;
  cout << "Cadena #2: "<<s2<<endl;
  cout << "Cadena #4: "<<s4<<endl;  
  
  // concatenando las dos que ya fueron convertidas s3 + s4 -> s5
  char s5[tam] ;
  strcpy( s5, s3 );
  strcat( s5, s4 );
  cout << "\nLa cadena #5 es la concatenación de las cadenas 3 y 4: "<<endl;
  cout << "Cadena #3: "<<s3<<endl;
  cout << "Cadena #4: "<<s4<<endl; 
  cout << "Cadena #5: "<<s5<<endl; 
  
  // contenga la cadena concatenada invertida s5 -> 5s
  char s6[tam] ;
  for (int x=0, y=tam-1; x<tam; x++, y--){
        s6[x]=s5[y];
    }
    s6[tam] = '\0';
    
  cout << "\nLa cadena #6 es la cadena #5 al revés: "<<endl;
  cout << "Cadena #5: "<<s5<<endl;
  cout << "Cadena #6: "<<s6<<endl; 
  
  cout <<"\nEl resultado de todas las cadenas es:"<<endl;
  cout << "Cadena #1: "<<s1<<endl;
  cout << "Cadena #2: "<<s2<<endl;
  cout << "Cadena #3: "<<s3<<endl;
  cout << "Cadena #4: "<<s4<<endl;
  cout << "Cadena #5: "<<s5<<endl;
  cout << "Cadena #6: "<<s6<<endl;
  
}

void convertirAMayusculasVocales( char *s ){
  while ( *s != '\0' ) {
    if ( *s == 'a' | *s == 'e' |*s == 'i' | *s == 'o' | *s == 'u'   ){
	  *s = toupper( *s ); // lo convierte a mayúscula
    }
    s++; 
  }
}
    
void convertirAMayusculasConsonantes( char *s ){
  while ( *s != '\0' ) {
    if ( *s != 'a' && *s != 'e' && *s != 'i' && *s != 'o' && *s != 'u' && isalpha(*s)  ){
	  *s = toupper( *s ); // lo convierte a mayúscula
    }
    s++; 
  }
}
   
  
