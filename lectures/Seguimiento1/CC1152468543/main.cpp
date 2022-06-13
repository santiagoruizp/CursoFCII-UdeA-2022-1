#include <iostream>
#include <string>
using namespace std;
using std::string;

int main()
{
  int option;
  float q;
  float h;
  float A;
  float Ts;
  float Ta;

  cout << "Ingrese el coeficiente de transferencia de calor (watts/m^2°C)." << endl;
  cin >> h;

  cout << "Ingrese la temperatura de la superficie (°C)." << endl;
  cin >> Ts;

  cout << "Ingrese la temperatura del medio ambiente (°C)." << endl;
  cin >> Ta;
  
  cout << "Ingrese 1 si la superficie es rectangular, 2 si es eliptica y 3 si es otra."<< endl;
  cin >> option;

  if (option == 1){
    float l;
    float a;
    float A;
    cout << "Ingrese el largo del rectangulo (m)" << endl;
    cin >> l;
    cout << "Ingrese el ancho del rectangulo (m)" << endl;
    cin >> a;
    A = a*l;
    cout << "El área es (m^2): " << A << endl; 
  }

  else if (option == 2){
    float m;
    float M;
    float A;
    cout << "Ingrese el eje menor (m)" << endl;
    cin >> m;
    cout << "Ingrese el eje mayor (m)" << endl;
    cin >> M;
    A=3.14*m*M;
    cout << "El área es (m^2)" << A << endl;
  }

  else {
    float A;
    cout << "Ingrese el area de su superficie. (m^2)" << endl;
    cin >> A;
    
  }

  q = h*A*(Ts - Ta);

  cout << "La rata de transferencia de calor (Joules/sec) es: "<< q << endl;
    }

  
