#ifndef PARTICULA_H
#define PARTICULA_H

class Particula{

	public: 
		Particula(double a, double b, double x, double k0, double dx, double dt, double sigma); 
		~Particula();
		void psi(double(*V)(double));	
		double geta();
		double getb();
		double getdx();	
	private:
		double a,b, x, k0, dx, dt, sigma;
};


#endif




