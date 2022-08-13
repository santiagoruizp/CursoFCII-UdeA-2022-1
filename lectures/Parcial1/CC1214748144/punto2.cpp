#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////
unsigned char perfecto(int n){
	float s=1;
	for(int c=2;c<n;c++){
		if(n%c==0){
			s+=c;
		}
	}
	if(s==n){
		return true; //si es un número perfecto entrega verdadero
	}
	else{
		return false; //si no es un número perfecto entrega falso
	}
}
////////////////////////////////////////////////////////////
int main(){
int n;
cout<<"\n Ingrese hasta qué número quiere saber los números perfectos que hay"<<endl;
cin>>n;
cout<<"\n Los números perfectos hasta "<<n<<" son:"<<endl;
for(int c=2;c<=n;c++){
	if(perfecto(c)==true){
		int iter=0;
		for (int s=1;s<c;s++){
			if(c%s==0){
				iter+=1;
			}	
		}
		cout<<"\n"<<c<<"=";
		int sum=0;
		for (int s=1; s<c;s++){
			if(c%s==0){
			sum+=1;
				if (sum==(iter)){
					cout<<s<<endl;//para que al imprimir la última vez no salga con un más a la derecha. 
				}
				else{
					cout<<s<<"+"; //si no es la última vez que va a imprimir, entonces se pone el más a la derecha. 
				    }
			}
		}			
	}	
}
return 0; 
}


