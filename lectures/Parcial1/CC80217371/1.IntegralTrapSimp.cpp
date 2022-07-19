#include <iostream>
#include <cmath>

using namespace std;

// integral metodo de simpson y trapezoide
// int_x_0 ^x_1 f(x)dx=h/2(f(x_0)+f(x_1)) ; h = x_0 - x_1
// int_x_0 ^x_2 f(x)dx=h/3(f(x_0)+4f(x_1)+f(x_2)) ; h = (x_0 - x_2)/2

double const valCaudrada = 2.667;
double const valCuarta = 6.400;
double const valRacional = 1.099;
double const valExpo = 6.389;


// lista de Funciones
double funcCuadrado(double x) // funcion de la forma x^2
{
    double valor = pow(x,2);// 
    return valor;
}

double funcCuarta(double x)
{
    double valor = pow(x,2)*pow(x,2) ;// funcion de la forma x^4
    return valor;
}

double funcRacional(double x)
{
    double valor = pow((1+x),-1); // funcion de la forma (1+x)^-1
    return valor; 
}

double funcExp(double x) // funcion de la forma e^x
{
    double valor=exp(x);
    return valor;
}

// Areas dependiendo del metodo
double areaTrapezoide(double (func) (double), double x_0, double x_1)
{
    double h = x_1-x_0;
    double area = h * (func(x_0)+func(x_1))/2.0;//+ func(x_1))/2;
    return area;
}
double areaSimpson(double (func) (double), double x_0, double x_2)
{
    double h = (x_2-x_0)/2;
    double x_1 = h + x_0;
    double area = h * (func(x_0)+4*func(x_1)+func(x_2))/3.0;//+ func(x_1))/2;
    return area;
}

int main()
{
    double a = 0.0, b = 2.0; // valores extremos a evaluar
    int N = 1; // numero de particiones
    double intervalo = b-a; // intervalo
    double paso = intervalo/N;
    double sumaAreaT=0, sumaAreaS=0; // inicializa las areas
    int opcion;

    cout << "Seleccione una de las opciones: x^2 [1], x^4 [2], (1+x)^-1 [3], e^x [4] ";
    cin >> opcion;
    
    switch (opcion)
    {
    case 1:
        for (double i=0; i < 2.0; i+=paso)
            {              
            sumaAreaT = sumaAreaT + areaTrapezoide(funcCuadrado,i,paso+i);
            sumaAreaS = sumaAreaS + areaSimpson(funcCuadrado,i,paso+i);
            }
    cout << "El area bajo la curva con el metodo del Trapezoide es: " << sumaAreaT << ", y su valor exacto es: "<< valCaudrada <<endl;
    cout << "El area bajo la curva con el metodo de Simpson es: " << sumaAreaS << ", y su valor exacto es: "<< valCaudrada <<endl;
        break;

    case 2:
        for (double i=0; i < 2.0; i+=paso)
            {              
            sumaAreaT = sumaAreaT + areaTrapezoide(funcCuarta,i,paso+i);
            sumaAreaS = sumaAreaS + areaSimpson(funcCuarta,i,paso+i);
            }
    cout << "El area bajo la curva con el metodo del Trapezoide es: " << sumaAreaT << ", y su valor exacto es: "<< valCuarta <<endl;
    cout << "El area bajo la curva con el metodo de Simpson es: " << sumaAreaS << ", y su valor exacto es: "<< valCuarta <<endl;
        break;

    case 3:
        for (double i=0; i < 2.0; i+=paso)
            {              
            sumaAreaT = sumaAreaT + areaTrapezoide(funcRacional,i,paso+i);
            sumaAreaS = sumaAreaS + areaSimpson(funcRacional,i,paso+i);
            }
    cout << "El area bajo la curva con el metodo del Trapezoide es: " << sumaAreaT << ", y su valor exacto es: "<< valRacional <<endl;
    cout << "El area bajo la curva con el metodo de Simpson es: " << sumaAreaS << ", y su valor exacto es: "<< valRacional <<endl;
        break;

    case 4:
        for (double i=0; i < 2.0; i+=paso)
            {              
            sumaAreaT = sumaAreaT + areaTrapezoide(funcExp,i,paso+i);
            sumaAreaS = sumaAreaS + areaSimpson(funcExp,i,paso+i);
            }
    cout << "El area bajo la curva con el metodo del Trapezoide es: " << sumaAreaT << ", y su valor exacto es: "<< valExpo <<endl;
    cout << "El area bajo la curva con el metodo de Simpson es: " << sumaAreaS << ", y su valor exacto es: "<< valExpo <<endl;
        break;
    
    default:
        break;
    }


    
}
