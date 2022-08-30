#include <iostream>
#include<limits>
using namespace std;

//Funciones prototipo

int busquedaBinaria(const int[], int, int); //arreglo, tamaño, clave
void imprimirArreglo(const int[], int);  //  arreglo, tamaño
void ordenarArreglo(int[], int); // arreglo, tamaño
void cambio(int&, int&); //primer número, segundo número
//los valores de dos elementos
int main()
{
  
  int clave{0};
  const int tamano = 13;
  int arreglo[tamano] = {7,10,4,800,12,1,9,8,700,63,43,2,66};
  //Primero se ordena el arreglo
  ordenarArreglo(arreglo,tamano);
  cout << "El arreglo ordenado actual es: " << endl;
  imprimirArreglo(arreglo,tamano);
  cout << "Ingrese valor a buscar: " << endl;
  
  // Evita que se ingresen valores no numericos
  while(!(cin >> clave)){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese solo valores numericos" << endl ;
  }
  
  int n= busquedaBinaria(arreglo,tamano,clave);
  if (n==-1){
      cout << "El valor no se encuentra en el arreglo" << endl;
  }
  else{
  cout<< "El valor se encuentra en la posición "<<busquedaBinaria(arreglo,tamano,clave)<<" del arreglo" << endl;
  
  }
  return 0;
}

void imprimirArreglo(const int arreglo[], int tamano)
{
  for (int i = 0 ; i < tamano ; i++)
    cout << "arreglo[" << i << "]=" << arreglo[i] << endl;
}
int busquedaBinaria(const int arreglo[], int tamano, int clave)
{
  int limSuperior = tamano-1;
  int limInferior = 0;
  int mitad;
  while (limInferior <= limSuperior)
    {
       mitad = (limSuperior + limInferior)/2;
      if (arreglo[ mitad] == clave)
 return  mitad;
      else
 if (clave < arreglo[ mitad])
   limSuperior= mitad-1;
 else
   limInferior= mitad+1;
    }
  return -1;
}
void ordenarArreglo(int arreglo[], int tamano)
{
  for (int i = 0; i< tamano -1 ; i++)
    for (int j = 0; j< tamano -1 ; j++)
      if (arreglo[j] > arreglo[j+1])
 cambio(arreglo[j],arreglo[j+1]);
}
void cambio(int &a1, int &a2)
{
  int a3 = a2;
  a2 = a1;
  a1 = a3;
}
