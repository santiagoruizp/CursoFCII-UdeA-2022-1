#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype> 

using namespace std;

char cadena1;
char cadena2;
void RecibirCadenas(const char* cadena1,const char* cadena2);
void convertirVocales( char *cadena );
void convertirConsonantes( char *cadena );


int main(){
    int cadena_1,cadena_2;
    cout << "ingrese la longitud de la cadena 1 y la 2 "<< endl;
    cin >> cadena_1 >> cadena_2;

    char cadena1[cadena_1]=""; 
    char cadena2[cadena_2]="";

    cout<<"Ingrese la cadena de texto 1 : "; 
    cin>>cadena1;

    cout<<"Ingrese la cadena de texto 2 : "; 
    cin>>cadena2;


    cout<<"\nlas cadenas ingresadas: \t"<<cadena1<<"\t y \t"<<cadena2<<"\t"<<endl;
    
    void RecibirCadenas(const char* cadena1,const char* cadena2);
    cout<<"comparacion de las cadenas: "; 
    
    if ( cadena1 == cadena2 ){
      cout <<" Cadena 1 si es igual a cadena 2 "<<endl;
      }
   else{
      if ( cadena1 > cadena2 )
         cout<<" cadena 1 es mayor que cadena 2 "<<endl;
      else 
         cout<<" cadena 2 es mayor a cadena 1"<<endl;
   }
    cout<<"\n";
    int tamanio = strlen( cadena1 ) + strlen( cadena2 );
    char vocalmayus[tamanio]; strcpy( vocalmayus, cadena1 );
    convertirVocales(vocalmayus);
    cout << "con las vocales en mayuscula\t"<<vocalmayus<<"\n";

    char constantesmayus[tamanio] ; strcpy( constantesmayus, cadena2 );
    convertirConsonantes(constantesmayus);
    cout << "con las constantes en mayuscula \t"<<constantesmayus<<"\n";
    cout<<"\n";
    return 0;
}

void RecibirCadenas(const char* cadena1, const char* cadena2){
    cout<<"comparacion de las cadenas: "; 
    
    if ( cadena1 == cadena2 ){
      cout <<" Cadena 1 si es igual a cadena 2 "<<endl;
      }
   else{
      if ( cadena1 > cadena2 )
         cout<<" cadena 1 es mayor que cadena 2 "<<endl;
      else 
         cout<<" cadena 2 es mayor a cadena 1"<<endl;
   }

    int tamanio = strlen( cadena1 ) + strlen( cadena2 );
    char vocalmayus[tamanio]; strcpy( vocalmayus, cadena1 );

    convertirVocales(vocalmayus);
    cout << "con las vocales en mayuscula es: \n"<<endl;
    cout << "\t"<<vocalmayus;

    char constantesmayus[tamanio] ; strcpy( constantesmayus, cadena2 );
    convertirConsonantes(constantesmayus);
    cout << "con las constantes en mayuscula es: \n"<<endl;
    cout << "\t"<<constantesmayus;

    
    char concatenadas[tamanio] ;
    strcpy( concatenadas, vocalmayus );
    strcat( concatenadas, constantesmayus );
    cout << "con las cadenas concatenadas: \n"<<endl;
    cout << "\t"<<concatenadas<<endl;
    
}

void convertirVocales( char *cadena_ ){
  while ( *cadena_ != '\0' ) {
    if ( *cadena_ == 'a' | *cadena_ == 'e' |*cadena_ == 'i' | *cadena_ == 'o' | *cadena_ == 'u'   ){
	  *cadena_ = toupper( *cadena_ );}
    cadena_++;
  }
}

void convertirConsonantes( char *cadena_ ){
  while ( *cadena_ != '\0' ) {
    if ( *cadena_ != 'a' && *cadena_ != 'e' && *cadena_ != 'i' && *cadena_ != 'o' && *cadena_ != 'u' && isalpha(*cadena_)  ){
	  *cadena_ = toupper( *cadena_ ); }
    cadena_++; 
  }
}