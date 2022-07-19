#include <iostream>
#include <string>
using namespace std;
using std::string;

int main()
{
  int option;
  float q;
  const float AIRCONV = 8.7;
  float Ts;
  float Ta;
  float A;
  float lchip = 0.02;
  float achip = 0.02;
  float qchip;
  float Tschip = 44;
  float Tachip = 40;

  cout << "Ingrese la temperatura de la superficie (°C)." << endl;
  cin >> Ts;

  cout << "Ingrese la temperatura del medio ambiente (°C)." << endl;
  cin >> Ta;
  
  cout << "Ingrese 1 si la superficie es rectangular, 2 si es eliptica y 3 si es otra."<< endl;
  cin >> option;

  if (option == 1){
    float l;
    float a;
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
    cout << "Ingrese el eje menor (m)" << endl;
    cin >> m;
    cout << "Ingrese el eje mayor (m)" << endl;
    cin >> M;
    A=3.141516*m*M;
    cout << "El área es (m^2)" << A << endl;
  }

  else {
    cout << "Ingrese el area de su superficie. (m^2)" << endl;
    cin >> A;
    
  }

  q = AIRCONV*A*(Ts - Ta);

  cout << "La rata de transferencia de calor (Joules/sec) es: "<< q << endl;
  
  qchip = AIRCONV*lchip*achip*(Tschip - Tachip);
  
  cout << "Para un chip rectangular de lado 2 cm y ancho 2 cm, la rata de transferencia de calor (Joules/sec) es: " << qchip << endl;
  
  
  
  }
