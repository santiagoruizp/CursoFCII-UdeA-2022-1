#include<iostream>
#include<cmath>
using namespace std;

int perfecto(int x){
    int sum=0;
    
    for(int i=1;i<x;i++){
        if ((x%i)==0){
            sum+=i;
        }
    }

    if(sum==x){
        cout << x << "es perfecto" << endl;
        cout << "sus dividores son \n" << endl;
        for (int j=1; j<x;j++){
            if((x%j)==0){
                cout << j << endl;
            }
        }
        return 1;
    }

    else{
        return 0;
    }
}

int main()
{
    int n=1000; //iteraciones
    cout << "Ingrese hasta que numero quiere verificar numeros perfectos: ";
    cin>>n;
    for (int k=1 ; k<=n ; k++)
    {
        perfecto(k);
    }
    return 0;
}