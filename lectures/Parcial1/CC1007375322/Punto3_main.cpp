#include "Punto3.h"

int main()
{
  //Se crean dos números complejos de prueba a y b
  Complejo a(1,7);
  Complejo b(-5,3.5);
  b.mostrarNumero();
  b.SumaComplejos(a.obtenerParteReal(),a.obtenerParteImaginaria());
  b.RestaComplejos(a.obtenerParteReal(),a.obtenerParteImaginaria());
  b.Producto(a.obtenerParteReal(),a.obtenerParteImaginaria());
  b.Division(a.obtenerParteReal(),a.obtenerParteImaginaria());
  a.norma();
  a.Conjugado();
  
  

  return 0;
  
}

