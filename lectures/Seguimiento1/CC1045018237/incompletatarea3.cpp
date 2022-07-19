#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class CalcularExponencial
{
public:
  explicit CalcularExponencial(double y)
    :valory (y)
  {

  }


  




  //funcion factorial 
  unsigned long facriatorial (unsigned long);
  int fact (int num)  
{
  int mm =1;
  double factorial = 1;

  if(num ==0){ factorial=1;}
  else{

    while(mm<a=num){
      factorial*=mm;
      mm++;
    }

  }

  return factorial;

}
int main()
{
  int j = 0;
  double diff;
  double mye = 1;

  cout << "expo de x es: " << exp(x) << endl;
  cout << " " << endl;

  while (j<2)
    {
      int sing = pow(1,j);

      mye = 1 + sing*(pow(x,j+1)/fact(j+1));

      cout << "exp para el termino: " << j << "es: " <<mye << endl;
      cout << " " << endl;

      j++;
    }

return 0;
}

  
  
private:
  double x;

private:
  double N;  //numero de terminos de la serie
};

