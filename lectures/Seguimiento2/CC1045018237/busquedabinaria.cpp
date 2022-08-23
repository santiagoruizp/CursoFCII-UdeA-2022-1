//busqueda binaria

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;


//prototipo de la función
int busquedaBinaria(const int [], int, int, int, int );


int main()
{

  const int tamanoArreglo = 15;
  int a[tamanoArreglo];
  int clave;

  for (int i = 0; i < tamanoArreglo; i++)
    a[i] = 2*i;

  cout << "introduzca un mumero entre 0 y 28 :";
  cin >> clave;

  //despliegaEncabezado( tamanoArreglo);

  int resultado = busquedaBinaria(a, clave, 0, tamanoArreglo-1, tamanoArreglo);

if (resultado  != -2)
  cout << "\n" << clave << " se encuentra en el elemento del arreglo: " << resultado << endl;

else
{
  cout << '\n' << clave << "no se encontro" << endl;
}


  


 
return 0;
}

//función para realizar la busqueda binaria dentro de un arreglo
int busquedaBinaria(const int b[], int claveBusqueda, int bajo, int alto, int tamano)
{
  int central;
    // repetición hasta que el subindice bajo sea mayor que el subindice alto
  while (bajo <= alto) {
    central = (bajo + alto) / 2; // determina el elemento central del sub arreglo en el que se busca
    //despliegaFila(b, bajo, central, alto, tamano ); // despliega el subarreglo utilizado en este ciclo de iteración
    if (claveBusqueda == b[ central ])
    {
        return central;
    }
    else if ( claveBusqueda < b[central])
    {
        alto = central -1;
    }
    else
    {
        bajo = central +1;

    }
        
    }

    return -1;
} //fin de la busqueda binaria
