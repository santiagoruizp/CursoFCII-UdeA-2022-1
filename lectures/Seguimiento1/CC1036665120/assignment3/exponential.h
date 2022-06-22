
#include <string> 
#include <tuple>
    
using namespace std;
    
// clase 
class ExponentialSeries
{
 public :
  ExponentialSeries(); 
  tuple<int, float> getNumberFromUser();
  double calculateSeries(float, int);
  double factorial(int);
  void mostrarResultado(float);
};