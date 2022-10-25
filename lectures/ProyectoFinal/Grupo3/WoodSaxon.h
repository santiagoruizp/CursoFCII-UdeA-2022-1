
#ifndef WOODSAXON
#define WOODSAXON
#include<vector>
#include<iostream>
using namespace std;

class WoodSaxon{

    public:
    WoodSaxon(double, double, unsigned int , unsigned int, string);
    void Calcular();
    void Potencial();
    void NumerovMethod(unsigned int);
    void SigmaConv();
    void SeccionEficazDif();
    void Guardar(string, int);
    double sigma;

    private:
    double Rmax=20.0, dx=0.1;
    double E, H2M, k, Mass;
    int N;
    unsigned int A, Z, lp_conv;
    vector <double> r;
    vector <double> V;
    vector <double> delta;
    vector <double> theta, dsigma, LP, sigmarrayConv;
    string Elem;
};

class Resonancias{

    public:
    Resonancias(double, unsigned int , unsigned int, string);
};
#endif