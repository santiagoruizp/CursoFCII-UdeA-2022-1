// LibroCalificar.h
#include <iostream>
#include <string>

using namespace std;

class calculo
{
 public:
  calculo( float, unsigned int ); // el constructor
  int factorial(  unsigned int ); 
  float exponencial();
  void imprime_factorial(unsigned int);
  void imprime_exponencial();

 private:
  unsigned int N;
  float x;
};
