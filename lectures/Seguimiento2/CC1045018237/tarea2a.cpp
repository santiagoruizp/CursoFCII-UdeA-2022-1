#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// funciones a utilizar
void RecibirCadenas (string, string);
string convertirVocales(string& str);
string convertirConsonantes(string& str);
string reverse(string& str);

 // cadenas a utilizar
string cadena1;
string cadena2;
string cadena3;
string cadena4;
string cadena5;
string cadena6;



int main()
{
    cout << "Escriba dos cadenas :"; // pedimos al usuario las dos cadenas
    cout << "La cadena 1 es: ";  //pedimos la cadena1
    getline(cin,cadena1);       // pedimos la cadena1 con espacios
    cout << "La cadena 2 es: ";  // pedimos la cadena2
    getline(cin,cadena2);        // pedimos la cadena2 con espacios
    RecibirCadenas(cadena1, cadena2); // llamamos a la funcion principal, esta llamara a las demas funciones
    
    

    return 0;
}

void RecibirCadenas(string, string) //RecibirCadenas será la función principal, con ella llamamos a las demas funciones
{
    cout << "La cadena 1  es:\n" 
         << cadena1 << endl; //nos enseña la cadena1 que se escribió
    
    cout << "La cadena 2 es:\n" // nos enseña la cadena2 que se escribió
         << cadena2 << endl;

 int resultado = cadena1.compare(cadena2); // llamamos la funcio compare par comparar las dos cadenas

 if ( resultado == 0 ) // creamos un if para que nos muestre un mensaje segun cual cadena es mayor
     cout << " Las dos palabras son iguales == 0\n";
   else{
     if ( resultado > 0 )
      cout << "La cadena 1 es mayor que la palabra 2  y > 0\n";
     else  (resultado < 0);
      cout << "La cadena 2 es mayor que la palabra 1  y < 0\n";
       }

    cadena3 = cadena1;
    cadena4 = cadena2;
  
 
    
    convertirVocales(cadena3); // llamamos a la funcion para convertir vocales a mayusculas
    cout << "La cadena 1 con vocales en mayusculas:\n " << cadena3 << endl; // la imprimimos

    convertirConsonantes(cadena4); // llamamos a la funcion convertir consonantes
    cout << "La cadena 2 con consonantes en mayusculas:\n " << cadena4 << endl; // la imprimimos

    string cadena5(cadena3 + cadena4); // concatenamos las dos nuevas cadenas
    cout << "Concatenacion de las cadenas 4 y 5:\n " << cadena5 << endl; // la imprimimos
    
    
    
    cadena6 = reverse(cadena5); // llamamos la funcion reverse para cambiar el orden de las palabras concatenadas
    cout << "Intercambio de caracteres en la ultima cadena:\n" << cadena6 << endl; // la imprimimos

    
}



string convertirVocales(string& str) // creamos una funcion para transformar las vocales en mayusculas
{
    int ln = str.length();
    for (int i = 0; i < ln; i++)  // creamos un for para recorrer la palabra y la cambia por una vocal mayuscula 
    {                              // si la vocal es minuscula
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] =='o' || str[i] == 'u')
        {str[i] = str[i] - 'a' + 'A';}
    }
    return str;
}

string convertirConsonantes(string& str) // creamos una funcion para hacer las consonates en mayusculas 
{
    int ln = str.length();
    for (int i = 0; i < ln; i++)  // creamos un nuevo for, pero esta vez le decimos al programa que si la letra es 
    {                              // diferente a una vocal , la cambie por mayuscula
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
        {str[i] = str[i] - 'b' + 'B';}

    }
    return str;
}

string reverse(string& str) // creamos una funcion para cambiar el oden de la palabra
{
    string rev;
    for (int i = str.size() - 1; i >= 0; i--) {
        rev = rev.append(1, str[i]); // utilizamos append para cambiar el orden de las letras
    };
 
    return rev;
}