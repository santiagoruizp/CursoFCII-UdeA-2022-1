#include <iostream>
#include <string> 
#include <cstring> 


using namespace std;

// Funciones prototipo

void convertirAMayusculas1( char * );  // Convierte cualquier minúscula en mayus
void imprimirCaracteres( const char * ); // Imprime usando apuntador a datos const
void RecibirCadenas( char *, char * ); // Función principal
void Comparar( char *, char * ); // Compara dos cadenas
void convertirAMayusculas2(char *); // Convierte consonantes minúscula en mayus
void invertirCadena( const char *, int ); //Invierte cadena

int main()
{   
    // Cadenas a recibir
    char frase1[20];
    char frase2[20];
    cout << "Ingrese la primera cadena: ";
    cin.getline(frase1, 20);
    cout << "Ingrese la segunda cadena: ";
    cin.getline(frase2, 20);
    RecibirCadenas(frase1,frase2);
    return 0;
}

void convertirAMayusculas1( char *sPtr )
{
  while ( *sPtr != '\0' ) 
    {
      if ( islower( *sPtr ) ) // si el caracter es minúscula,
	*sPtr = toupper( *sPtr ); // lo convierte a mayúscula
      sPtr++; // mueve sPtr al siguiente carácter en la cadena
    } 
}

void convertirAMayusculas2( char *sPtr )
{
  while ( *sPtr != '\0' ) 
    {
    if ( *sPtr != 'a' && *sPtr != 'e' && *sPtr != 'i' && *sPtr != 'o' && *sPtr != 'u'  ) 
    // Convierte consonantes en mayuscula
	    *sPtr = toupper( *sPtr );

    sPtr++; // mueve sPtr al siguiente carácter en la cadena
    }
     
}

void invertirCadena( const char *sPtr, int n )
{
    sPtr+=n; //Posición final de memoria del char
    int c=0;
    while (c<=n) //
    {
         sPtr-=1; // Cambia posición
    cout << *sPtr; 
       c+=1;
    }
  cout << *sPtr;
}

// Compara dos canedas
void Comparar(char a[], char b[]){
    
    int n = strcmp( a, b); 
    
    //condiciones de comparación
    if (n==0){ 
        cout << "Las cadenas son iguales";
        
    }
    if (n>0) {
        cout << "La primera cadena es mayor";
        
    }
    if (n<0) {
        cout << "La primera cadena es menor";
        
    }
    
}

void imprimirCaracteres( const char *sPtr )
{
for ( ; *sPtr != '\0'; sPtr++ ) // no hay inicialización
  cout << *sPtr; // muestra el carácter sin modificación
}

void RecibirCadenas(char a[], char b[]){
    
    cout << "La primera cadena es:  ";
    imprimirCaracteres(a);
    
    cout<< endl; 
    cout << "La segunda cadena es:  ";
    imprimirCaracteres(b);
    cout<< endl; 
    
    Comparar(a,b);
    cout << endl;
    cout << "La primera cadena en Mayuscula es: ";
    convertirAMayusculas1(a); // Convierte la primera Cadena a Mayuscula
    imprimirCaracteres(a);
    cout<< endl;
    cout << "La segunda cadena con consonantes en Mayuscula es: ";
    convertirAMayusculas2(b); // Convierte la primera Cadena a Mayuscula
    imprimirCaracteres(b);
    strncat(a, b, 20); //concatenada
    cout<< endl;
    cout << "La cadena concatenada es: ";
    imprimirCaracteres(a);
    cout<< endl;
    cout << "La cadena invertida: ";
    invertirCadena(a,strlen( a));
    
    
}
