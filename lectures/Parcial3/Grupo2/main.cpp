#include "parabolicas.h"
using namespace std;

int main(){
    
    Parabolicas parabolic("Parabolicas");
    
    
    // void funcion(l, m , N , T, alpha  )
    cout<<"Metodo de diferencias regresivas\n"<<endl;
    parabolic.regresivas(1, 10, 100, 1, 1  );

    cout<<"\n\nMetodo de Crank-Nicolson\n"<<endl;
    parabolic.crankNicolson(1, 10, 100, 1, 1  );
 
    //system("pause");
    return 0;
        
}
