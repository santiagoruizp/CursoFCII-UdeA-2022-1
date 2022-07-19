// Tarea 3 Alejandro Restrepo Giraldo CC: 1001389709


# include <iostream>
# include <cmath>
# include <iomanip>

using namespace std;

class Exponencial{

  public:
  
  // Constructor
  Exponencial(double Valor, int Orden){
    x = Valor;
    N = Orden;
  }
  
  // Método para calcular el factorial
  unsigned long int Factorial(int n){
    
    unsigned long int fact = 1;
    
    // Factoriales especiales
    if (n == 0 || n == 1)
      return fact;
      
    else{
    
    // Cálculo de los factoriales
    for (int i = 1; i <= n; i++) {
      fact *= i;
      }
    return fact; 
    }
    
  }
  
  // Exponencial por series de Taylor
  float Expvalue(double x, int N){
  
    float Exp = 0;
    
    // Cálculo de los términos indicados de la serie
    for (int i = 0; i <= N; i++){
      Exp += pow(x,i)/Factorial(i);
    }
    
    return Exp;
    
  }
  
  // Función para imprimir el resultado
  void DisplayResult(){
  
    cout<<endl<<"El valor calculado es e^"<<setprecision(12)<<x<<" = "<<Expvalue(x, N)<<endl;
    
  }
  
  
  private:
  
  // Variables para almacenar el valor y orden
  double x;
  int N;
 
};


int main(){

  double x;
  int N;
  
  cout<<"Este programa calcula e^x mediante la expansión de Taylor hasta un orden indicado. Para un valor correcto no supere el orden 23 pues es mayor que el almacenamiento de un unsigned long int lo cual trae imprecisiones en el cálculo. Se imprimen los valores con 10 cifras significativas."<<endl<<endl;
  cout<<"Ingrese el valor de x: ";
  cin>>x;
  cout<<endl<<"Ingrese el valor del orden: ";
  cin>>N;
  
  // Cálculo y resultado
  Exponencial Calculo(x, N);
  Calculo.DisplayResult();
    
  return 0;
  
}

 




