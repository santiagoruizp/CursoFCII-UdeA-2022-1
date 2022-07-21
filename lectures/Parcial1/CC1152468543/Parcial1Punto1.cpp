#include <iostream>
#include <cmath>

using namespace std;

float Trapezoidal(int N, float a, float b, float (*f)(float))
{	
	int n = 1;
	float sum = f(a)+f(b);
	float dx = (b-a)/N;
	float x_i = a;
	while(n <= N-1){
		sum += 2*f(x_i);
		x_i=x_i+dx;
		n+=1;
	}
	return 0.5*dx*sum;
}

float Simpson(int N, float a, float b, float (*f)(float))
{
	if(N%2==1){
		float N = N+1;
	}
	
	float sum = f(a) + f(b);
	float x_i=a;
	float dx = (b-a)/N;
	int n=1;
	
	while(n<=N-1){
		if(n%2==0){
			sum+=2*f(x_i);
		}
		else{
			sum+=4*f(x_i);		
		}
		x_i=x_i+dx;
		n+=1;
	}
	return 0.333*dx*sum;
}

float exponential(float x)
{
	return exp(x);
}

int main()
{
	cout<<"El valor de la integral de e^x entre 0 y 1 usando la regla trapezoidal es: "<<Trapezoidal(1000,0,1,&exponential)<<endl;
	cout<<"El valor de la integral de e^x entre 0 y 1 usando la regla de Simpson es: "<<Simpson(1000,0,1,&exponential)<<endl;
	cout<<"El valor debería ser algo como 1.71828. De esta forma, se puede ver que la integración usando regla trapezoidal da un resultado más preciso."<<endl;
	return 0;
}

