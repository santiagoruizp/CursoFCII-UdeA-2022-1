
// Ecuación de Poisson
#ifndef EC_ELIPT
#define EC_ELIPT

#include<vector>
using namespace std;

class EcEliptica{

    public:
    EcEliptica(double, double, double, double, unsigned int, unsigned int);
    void Mesh();
    void imprimir();
    void guardar();
    int GaussSeidel(double(*)(double, double),double(*)(double, double,double, double,double, double));
    void error(double(*)(double, double));

    private:
    double a,b,c,d,Tol,h,k;
    unsigned int n,m,N;
    vector<vector<double>> W;
    vector<double> x;
    vector<double> y;
};

#endif