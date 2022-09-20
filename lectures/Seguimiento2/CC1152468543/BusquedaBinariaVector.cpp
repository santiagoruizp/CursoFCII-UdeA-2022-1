#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int Search(const vector<int> &vect, int a)
{
	bool statement = true;
	int inf = 0;
	int sup = vect.size();
	int val = 0;
	int j=0;
	int l = vect.size();
	
	while (statement == true){
		//cout<<"sup "<<sup<<"inf "<<inf<<endl;
		l = (sup-inf)/2;
		if (vect[l+inf]==a){
			statement == false;
			val = l+inf;
			break;
		}
		if (vect[l+inf]>a){
			sup = l+inf;
			statement = true;
		}
		if (vect[l+inf]<a){
			inf = l+inf;
			statement = true;
		}
		//if (l==1){
			//statement = false;
			//val = inf + 1;
			//break;
		//}
		if (l==0){
			val=0;
			break;
		}
	
	} 
	if (val == 0){
		cout<<"No se encontró el valor dentro de la lista."<<endl;
	}
	else{
		cout<<"El indice en el cual ocurre el valor es: "<<val<<endl;
	}
	return val;
	
}

int main()
{
	vector< int > F(20);
	for (int i = 0; i<=20; i++){
		F[i]=pow(i,3);
	}
	
	//sort(F.begin(), F.end());
	int a;
	cout<<"Introduzca el valor númerico a buscar en la lista"<<endl;
	cin>>a;
	Search(F,a);
		
	return 0;
}

