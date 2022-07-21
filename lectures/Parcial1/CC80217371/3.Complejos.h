#include <iostream>
#include <string>

using namespace std;

class ImOperaciones
{
    public:
    ImOperaciones(string); //Contructor
    void mostrarMensaje();
    void recibirParametros();
    string signoReSum(double,double);
    string signoImSum(double,double);
    string signoReRes(double,double);
    string signoImRes(double,double);
    void suma(double,double,double,double);
    void resta(double,double,double,double);
    void multiplicacion(double, double, double, double);
    void division(double, double, double, double);
    void mostrarResultado();

    private:
    double z1_re;
    double z1_im;
    double z2_re;
    double z2_im;
};