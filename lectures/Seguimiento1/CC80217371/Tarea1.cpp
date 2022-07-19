// Transferencia de calor
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Heat convection ---> q = h*A*(T_s-T_a)
/*Write, compile, and run a C++ program that accepts a substance’s surface area,
 a substance’s surface temperature, and the ambient air temperature as inputs and
  displays the heat transfer rate through air */
int main()
{
    const double h=8.7; //units watts/m^2°C
    const double PI=3.1416;
    double A, T_s, T_a, q; // Area, temperatura sustancia, temperatura ambiente y velocidad de transferencia respectivamente
    double ancho, largo, ejeMayor, ejeMenor, Area;
    int i;

    cout << "Ingrese la temperatura ambiente (°C): ";
    cin >> T_a;
    cout << "Ingrese la temperatura de la sustancia (°C): ";
    cin >> T_s;
    cout << "Tipos de superficie: Rectangular [1] Eliptica[2] Otra[3]";
   
    cout << "Escoja un tipo de superficie: ";
    cin >> i;
    
    switch (i)
    {
    case 1:
        cout << "Usted ha escojido superficie rectangular" << endl;
        cout << "Ingrese el ancho de la superficie (m): ";
        cin >> ancho;
        cout << "Ingrese el largo de la superficie (m): ";
        cin >> largo;
        A = ancho * largo;
        q = h*A*(T_a-T_s);    //q = h*A*(T_s-T_a)

        cout << setiosflags(ios::fixed)
         << setiosflags(ios::showpoint)
         << setprecision(4)
         << "La velocidad de transferencia de calor es: " << q << " Joules/s" << endl;
        break;

    case 2:
        cout << "Usted ha escojido superficie eliptica" << endl;
        cout << "Ingrese el eje mayor de la superficie (m): ";
        cin >> ejeMayor;
        cout << "Ingrese el eje menor de la superficie (m): ";
        cin >> ejeMenor;
        A = PI*ejeMayor*ejeMenor;
        q= h*A*(T_a-T_s);    //q = h*A*(T_s-T_a)

        cout << setiosflags(ios::fixed)
         << setiosflags(ios::showpoint)
         << setprecision(4)
         << "La velocidad de transferencia de calor es: " << q << " Joules/s" << endl;
        break;
    
    case 3:
        cout << "Usted ha escojido ingresar la superficie" << endl;
        cout << "Ingrese el area (m^2): ";
        cin >> Area;
        A = Area;
        q= h*A*(T_a-T_s);    //q = h*A*(T_s-T_a)

        cout << setiosflags(ios::fixed)
         << setiosflags(ios::showpoint)
         << setprecision(4)
         << "La velocidad de transferencia de calor es: " << q << " Joules/s" << endl;
        break;

    default:

        break;
    }
}
