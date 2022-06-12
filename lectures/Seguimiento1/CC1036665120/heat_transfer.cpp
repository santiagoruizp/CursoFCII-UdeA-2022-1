#include <iostream>
#include <math.h>
#include "heat_transfer.h"

using namespace std;


HeatTransfer::HeatTransfer(){

} 

float HeatTransfer::stablishArea()
{
    // ÁREA DE LA SUPERFICIE
    float eje1=0;
    float eje2=0;
    float area=0;

    // opciones de elección inicial
    cout << "Elije un número: Selecciona una superficie o siga un ejemplo:" << endl;
    cout << "1. Rectángulo" << endl;
    cout << "2. Elipse" << endl;
    cout << "3. Otra superficie" << endl;
    cout << "4. Seguir un ejemplo: Tasa de transferencia de calor de un chip en la consola de una computadora." << endl;

    int shape;
    cin >> shape;

    // verifica que se ingrese un número y vuelve a hacer un input 
    while(cin.fail()) {
        cout << "ERROR: Debe marcar un número" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> shape;
    }
    
    // casos de superficies a calcular
    switch(shape)
    {
    case 1:
      cout << "-- Elegiste un rectángulo --" << endl;
      cout << "Ingresa la altura en metros:";
      cin >> eje1;
      cout << "Ingresa el ancho en metros:";
      cin >> eje2;
      area = eje1 * eje2;
      break;
    case 2:
      cout << " -- Elegiste una Elipse -- " << endl;
      cout << "Ingresa el semieje mayor en metros: ";
      cin >> eje1;
      cout << "Ingresa el semieje menor en metros: ";
      cin >> eje2;
      area = M_PI*eje1 * eje2;
      break;
    case 3:
      cout <<"Ingresa el área superficial en en m^2:";
      cin >> area;
      break;
    case 4:
      // en el caso que haya decidido seguir el ejemplo
      cout <<"La ficha rectangular del chip tiene una longitud de 2 cm y un ancho de 2 cm."<< endl;;
      area = 0.0004;
      break;
    default:
      // si marca un número que no está en las opciones  
      cout <<"ERROR: Debes marcar uno de los números para seleccionar el tipo de figura."<< endl;
      cout <<"Entonces, ingresa el área superficial en en m^2:";
      cin >> area;
      break; 
    }

    return area;
} 

float HeatTransfer::stablishTempSurface()
{
    // TEMPERATURA DE LA SUPERFICIE
    float temp_s=0;
    cout << "Ingresa la temperatura superficial en ºC. Pero, si estás siguiendo el ejemplo, marca -1: ";
    cin >> temp_s;

    // verifica que se ingrese un número y vuelve a hacer un input 
    while(cin.fail()) {
        cout << "ERROR: Debe marcar un número" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> temp_s;
    }

    // si el usuario marca -1 se establece la temperatura del ejemplo
    if (temp_s==-1)
    {
      temp_s=44;
    }
    
    return temp_s;
} 

float HeatTransfer::stablishTempEnv()
{   
    // TEMPERATURA DEL AMBIENTE 
    float temp_env=0;
    cout << "Ingresa la temperatura del ambiente en ºC. Pero, si estás siguiendo el ejemplo, marca -1: ";
    cin >> temp_env;
    
    // verifica que se ingrese un número y vuelve a hacer un input 
    while(cin.fail()) {
        cout << "ERROR: Debes marcar un número" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> temp_env;
    }

    // si el usuario marca -1 se establece la temperatura del ejemplo
    if (temp_env==-1)
    {
      temp_env=40;
    }
    return temp_env;
} 

float HeatTransfer::calcHeatTransfer(float area, float temp_surf, float temp_env)
{
    // CÁLCULO DE LA FUNCIÓN DE TRANSFERENCIA
    float AIRCONV = 8.7; // watts/m2°C --> heat transfer coefficient
    float q = AIRCONV * area * ( temp_surf - temp_env );
    return q;
} 

void HeatTransfer::mostrarMensaje(float q)
{ 
  // MENSAJE CON EL RESULTADO 
  cout << "La función de transferencia es:" << endl;
  cout << "q = hA(Ts-Te) = " << q  << "W/m2" << endl;
} 

