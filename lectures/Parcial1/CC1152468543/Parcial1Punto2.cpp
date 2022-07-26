#include <iostream>
#include <cmath>

using namespace std;

int perfecto(int numero)
{
	int sum = 0;
	int i = 1;
	while(i < numero){
		if(numero%i==0)
		{
			sum+=i;
		}
		i+=1;
	}
	
	if(numero == sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void determinarperfecto(int numero)
{
	
	if(perfecto(numero)==1)
	{
		cout<<"El número " << numero << " es perfecto."<<endl;
	}
	else
	{
		cout<<"El número " << numero << " no es perfecto."<<endl;
	}
}

int main()
{	
	int k = 1;
	//Se imprimen a continuación los números perfectos hasta 10000, de esta forma, se están imprimiendo los que van hasta 1000 al tiempo que se pone a prueba la computadora.
	while(k<=10000)
	{
		int condition = perfecto(k);
		if(condition==1)
		{
			determinarperfecto(k);
			int i = 1;
			cout<<"Los divisores de "<< k <<" menores que él mismo, son: "; 
			while(i<k)
			{
				if(k%i==0)
				{
					cout<< i << ", ";
				}
				i+=1;
			}
			cout<<"se puede verificar que el número es perfecto sumando estos divisores."<<endl;

		}
		k+=1;
	}
	
	return 0;
}
