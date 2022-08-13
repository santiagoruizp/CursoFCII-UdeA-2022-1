#include <iostream>
#include <cmath>
#include "Complejos.h"

using namespace std;

ImOperaciones::ImOperaciones(string) // Inizializa
{
    z1_re;
    z1_im;
    z2_re;
    z2_im;    
}

void ImOperaciones::mostrarMensaje() // Muestra el mensaje de bienvenida
{
    cout << "Bienvenido, aqui podra efectuar algunas operaciones con numeros complejos" << endl;
}

void ImOperaciones::recibirParametros()
{
    cout << "Por favor ingrese un par de numeros: "<<endl;
    cin >> z1_re;
    cin >> z1_im;
    if (z1_im<0)
    {
        cout << "El numero complejo ingresado es: "<< z1_re << "-"<<abs(z1_im)<<"i"<<endl;
    }
    else
    {
        cout << "El numero complejo ingresado es: "<< z1_re << "+"<<z1_im<<"i"<<endl;
    }

    cout << "Por favor ingrese un segundo par de numeros: "<<endl;
    cin >> z2_re;
    cin >> z2_im;
    if (z2_im<0)
    {
        cout << "El primer numero complejo ingresado es: "<< z2_re << "-"<<abs(z2_im)<<"i"<<endl;
    }
    else
    {
        cout << "El segundo numero complejo ingresado es: "<< z2_re << "+"<<z2_im<<"i"<<endl;
    }
}

string ImOperaciones::signoReSum(double sigA, double sigB)
{
    if (sigA+sigB>=0)
    {return " ";}
    else
    {return "-";}     
}
string ImOperaciones::signoImSum(double sigA, double sigB)
{
    if (sigA+sigB>=0)
    {return "+";}
    else
    {return "-";} 
}
string ImOperaciones::signoReRes(double sigA, double sigB)
{
    if (sigA-sigB>=0)
    {return " ";}
    else
    {return "-";}    
}
string ImOperaciones::signoImRes(double sigA, double sigB)
{
    if (sigA-sigB>=0)
    {return "+";}
    else
    {return "-";} 
}
void ImOperaciones::suma(double aR, double aI, double bR, double bI)
{
    double sumRe = aR + bR;
    double sumIm = aI + bI;
    cout << signoReSum(aR , bR) << abs(sumRe) <<signoImSum(aI , bI)<< abs(sumIm) <<"i"<< endl;
}
// ajustar signo
void ImOperaciones::resta(double aR, double aI, double bR, double bI)
{
    double restRe = aR - bR;
    double restIm = aI - bI;
    cout << signoReRes(aR , bR) <<abs(restRe) <<signoImRes(aI , bI)<<abs(restIm)<<"i"<< endl;
}

void ImOperaciones::multiplicacion(double aR, double aI, double bR, double bI)
{
    double multRe = aR*bR-aI*bI;
    double multIm = aR*bI+aI*bR;
    if (multIm<0)
        {
            cout << multRe<<"-"<<abs(multIm)<<"i";
        }
    else
        {
            cout << multRe<<"+"<<abs(multIm)<<"i";    
        }
}
 
void ImOperaciones::division(double aR, double aI, double bR, double bI)
{
    double dividendo = bR*bR + bI*bI;
    if (dividendo != 0)
        {
        double diviRe = (aR*bR+aI*bI)/dividendo;
        double diviIm = (aI*bR-aR*bI)/dividendo;
        if (diviIm<0)
            {
                cout << diviRe<<"-"<<abs(diviIm)<<"i";
            }
        else
            {
                cout << diviRe<<"+"<<abs(diviIm)<<"i";    
            }
        }
    else
        {
            cout<<"La operacion no es posible";
        }
}

void ImOperaciones::mostrarResultado()
{
    int entrada;
    cout<<"Ingrese una de las opciones: Suma [1], Resta [2], Multiplicacion [3], Division [4]: "<<endl;
    cin>> entrada;
    switch (entrada)
    {
    case 1:
        suma(z1_re, z1_im, z2_re, z2_im);
        break;
    case 2:
        resta(z1_re, z1_im, z2_re, z2_im);
        break;
    case 3:
        multiplicacion(z1_re, z1_im, z2_re, z2_im);
        break;
    case 4:
        division(z1_re, z1_im, z2_re, z2_im);
        break;
    
    default:
        break;
    }    
}
