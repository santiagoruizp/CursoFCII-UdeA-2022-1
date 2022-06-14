#include <iostream>
#include <cmath>

using namespace std;
//#define PI 3.1416
int main()
{
  const float PI  = 3.1416;
  const float AIRCONV=8.7;
  string var;
  float q{0};
  int T_s{0};
  int T_a{0};
  
  cout << "Calculo de la tasa de calor transferido. Ingrese el número de acuerdo a la superficie de interes:" << endl;
  cout << "1. Area rectangular"<< endl;
  cout << "2. Area eliptica" << endl;
  cout << "3. Otra" << endl;
  cin >> var;
  while (var!="1" and var!="2" and var!="3"){
    cout << "Ingrese un valor correcto: "<< endl;
    cin >> var;
    }
  cout << "Ingrese Temperatura de la superficie en grados centigrados: "<< endl;
  cin >> T_s;
  cout << "Ingrese Temperatura del ambiente en grados centigrados: "<< endl;
  cin >> T_a;
  

  if (var=="1"){
    float largo{0};
    float ancho{0};
    cout << "Ingrese largo del rectangulo en metros: " << endl;
    cin >> largo;
    cout << "Ingrese ancho del rectangulo" << endl;
    cin >> ancho;
    cout << "La tasa de calor transferido es: "<< (T_s-T_a)*largo*ancho*AIRCONV << " watts";
  }
  if (var=="2"){
    float semi_mayor{0};
    float semi_menor{0};
    cout << "Ingrese el semi-eje mayor en metros: " << endl;
    cin >> semi_mayor;
    cout << "Ingrese el semi-eje menor en metros" << endl;
    cin >> semi_menor;
    cout << "La tasa de calor transferido es: "<< PI*semi_mayor*semi_menor*AIRCONV*(T_s-T_a) << " watts";
    
  }
  if (var=="3"){
    float Area{0};
    cout << "Ingrese el area en metros: " << endl;
    cin >> Area;
    cout << "La tasa de calor transferido es: "<< Area*AIRCONV*(T_s-T_a) << " watts";
  }
  
  return 0;

   }
