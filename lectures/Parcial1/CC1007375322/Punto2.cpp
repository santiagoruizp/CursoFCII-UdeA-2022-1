#include <iostream>
#include <string>


using  namespace std;

void Perfecto(int); //Prototipo función define si un número es Perfecto

int main()
{
  int i=1;
  int numax;
  cout << "Ingrese el número hasta el que deseaevaluar: "<<endl;
  cin >> numax;
  
  for (i; i<=numax;i++)
  {
    Perfecto(i);
  }

}
void Perfecto(int i)
{
  int j=1;
  int sum=0;
  string strsum="";
  for (j; j<=i/2; j++)
    {
      if((i%j)==0)
	{
	  sum+=j;
	  strsum+=to_string(j)+"+";
	}
    }
  if(sum==i)
    {
      cout << "El número "<<i<< " es un número perfecto y sus divisores son: "<<strsum<< endl;
    }
}
