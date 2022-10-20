#include "potencial_inter.cpp"
#include <cmath>
#include <fstream>

using namespace std;

double V(double x);

int main(){
	const double pi = 3.14159265358979323846; 
	double a=0; 
	double b=15; 
	double x=-7.5;
	double k0=3.0*pi;  //armónico
	//double k0=17.0*pi; //pozo 
	double dx = 0.02;
	double sigma = 0.5;
	double dt=dx*dx/4; //armónico
	//double dt=dx*dx/2; //pozo
	
	Particula arm( a,  b,  x,  k0,  dx, dt,  sigma);
	arm.psi(&V);
	arm.~Particula();
	return 0;
}

double V(double x){
	return 5*pow(x,2); //potencial de oscilador armónico
}


/*double V(double x){
	return 0; //potencial de pozo infinito. 
}*/

