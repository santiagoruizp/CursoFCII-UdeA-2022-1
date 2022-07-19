#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;
//#define PI 3.1416

//Programa que permite el calculo del calor transferido en función del area y la diferencia de temperaturas de la superficie y el ambiente.
// Para el punto b) ingresar los siguientes datos en el orden en que el programa compila: 1, 44, 40, 0.02, 0.02
int main()
{
  //Definición de variables
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
  while (var!="1" and var!="2" and var!="3"){ //Evita que se ingresen datos no deseados.
    cout << "Ingrese un valor correcto: "<< endl;
    cin >> var;
    }
  cout << "Ingrese Temperatura de la superficie en grados centigrados: "<< endl;
  cin >> T_s;
  cout << "Ingrese Temperatura del ambiente en grados centigrados: "<< endl;
  cin >> T_a;
  
  //opciones de acuerdo al enunciado.
  if (var=="1"){
    float largo{0};
    float ancho{0};
    cout << "Ingrese largo del rectangulo en metros: " << endl;
    cin >> largo;
    cout << "Ingrese ancho del rectangulo en metros" << endl;
    cin >> ancho;
    cout << "La tasa de calor transferido es: "<< fixed << setprecision(3) << (T_s-T_a)*largo*ancho*AIRCONV << " watts";
  }
  if (var=="2"){
    float semi_mayor{0};
    float semi_menor{0};
    cout << "Ingrese el semi-eje mayor en metros: " << endl;
    cin >> semi_mayor;
    cout << "Ingrese el semi-eje menor en metros" << endl;
    cin >> semi_menor;
    cout << "La tasa de calor transferido es: "<< fixed << setprecision(3) << PI*semi_mayor*semi_menor*AIRCONV*(T_s-T_a) << " watts";
    
  }
  if (var=="3"){
    float Area{0};
    cout << "Ingrese el area en metros: " << endl;
    cin >> Area;
    cout << "La tasa de calor transferido es: "<< fixed << setprecision(3) << Area*AIRCONV*(T_s-T_a) << " watts";
  }
  return 0;

   }
