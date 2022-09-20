
#include<cmath>
#include<iostream>
#include<iomanip>
#include<fstream>
#include "EcEliptica.h"

// Constructor
EcEliptica::EcEliptica(double a0, double b0, double c0, double d0, unsigned int n0, unsigned int m0){

    a=a0, b=b0, c=c0, d=d0, n=n0, m=m0;
    // Número máximo de iteraciones
    N=100000;
    // Tolerancia
    Tol=1/pow(10,20);
    // Se crea el grid
    Mesh();
};

// Inicialización de valores en x, y. Se crea el grid de solución W como vector dos dimensional, se llena inicialmente con 0

void EcEliptica::Mesh(){

    h = (b - a)/n;
    k = (d - c)/m;

    for(int j=0;j<=m-1;j++){
        y.push_back(c+j*k);
    }
    for(int i=0;i<=n-1;i++){
        x.push_back(a+i*h);
    }

    for (int j = 0; j<=m-1; j++){
        vector<double> vf;
        for (int i = 0; i<=n-1; i++){
            vf.push_back(0);
        }
        W.push_back(vf);
    }

};

// Solución Ec Diferencial por Gauss-Seidel acorde al pseudo-código del libro Burden, Numerical analysis 9th ed
//parámetros: función f inhomogénea y g(x,y) función en fronteras, g recibe a,b,c,d que son las fronteras en x y y respectivamente

int EcEliptica::GaussSeidel(double(*f)(double, double),double(*g)(double, double,double, double,double, double)){

    // Se señala paso a paso del seudo-cógido

    double lambda= pow(h,2)/pow(k,2);
    double mu = 2*(1+lambda);
    unsigned int l=1;

    while (l<=N){

        // Step 7
        double z=(-h*h*f(x[1],y[m-1])+g(a,y[m-1],a,b,c,d)+lambda*g(x[1],d,a,b,c,d)+lambda*W[m-2][1]+W[m-1][2])/mu;
        double norm= abs(z-W[m-1][1]);
        W[m-1][1] = z;

        // Step 8
        for(int i=2; i<=n-2;i++){
            z=(-h*h*f(x[i],y[m-1])+lambda*g(x[i],d,a,b,c,d)+W[m-1][i-1]+W[m-1][i+1]+lambda*W[m-2][i])/mu;
            if(abs(W[m-1][i]-z)>norm){
                norm=abs(W[m-1][i]-z);
            }
            W[m-1][i]=z;
        }

            // Step 9
            z=(-h*h*f(x[n-1],y[m-1])+g(b,y[m-1],a,b,c,d)+lambda*g(x[n-1],d,a,b,c,d)+W[m-1][n-2]+lambda*W[m-2][n-1])/mu;
            if(abs(W[m-1][n-1]-z)>norm){
                norm=abs(W[m-1][n-1]-z);
            }
            W[m-1][n-1]=z;

            // Step 10

            for(int j=m-2;j>=2;j--){
                // Step 11
                z=(-h*h*f(x[1],y[j])+g(a,y[j],a,b,c,d)+lambda*W[j+1][1]+lambda*W[j-1][1]+W[j][2])/mu;
                if(abs(W[j][1]-z)>norm){
                    norm=abs(W[j][1]-z);
                }
                W[j][1]=z;


                // Step 12
                for(int i=2;i<=n-2;i++){
                    z=(-h*h*f(x[i],y[j])+W[j][i-1]+lambda*W[j+1][i]+W[j][i+1]+lambda*W[j-1][i])/mu;
                    if(abs(W[j][i]-z)>norm){
                        norm=abs(W[j][i]-z);
                    }
                    W[j][i]=z;
                    
                }

                // Step 13
                z=(-h*h*f(x[n-1],y[j])+g(b,y[j],a,b,c,d)+W[j][n-2]+lambda*W[j+1][n-1]+lambda*W[j-1][n-1])/mu;
                if(abs(W[j][n-1]-z)>norm){
                    norm=abs(W[j][n-1]-z);
                }
                W[j][n-1]=z;               
            }

            // Step 14
            z=(-h*h*f(x[1],y[1])+g(a,y[1],a,b,c,d)+lambda*g(x[1],c,a,b,c,d)+lambda*W[2][1]+W[1][2])/mu;
            if(abs(W[1][1]-z)>norm){
                norm=abs(W[1][1]-z);
            }
            W[1][1]=z; 


            // Step 15
            for(int i=2;i<=n-2;i++){
                z=(-h*h*f(x[i],y[1])+lambda*g(x[i],c,a,b,c,d)+W[1][i-1]+lambda*W[2][i]+W[1][i+1])/mu;
                if(abs(W[1][i]-z)>norm){
                    norm=abs(W[1][i]-z);
                }
                W[1][i]=z;

            }
            
            // Step 16
            z=(-h*h*f(x[n-1],y[1])+g(b,y[1],a,b,c,d)+lambda*g(x[n-1],c,a,b,c,d)+W[1][n-2]+lambda*W[2][n-1])/mu;
            if(abs(W[1][n-1]-z)>norm){
                norm=abs(W[1][n-1]-z);
            }
            W[1][n-1]=z;

            // Step 17, 18 y 19
            if(norm<=Tol){
                cout<< endl <<"Convergencia en:  "<< l<<" # pasos"<<endl<<"W[i,j]:"<<endl;
                return 1;
            }

        // Step 20
        l++;
    }

    // Step 21
    cout<< "Número máximo excedido"<<endl;
    return 0;

}


// Función para imprimir matriz W[i][j]
void EcEliptica::imprimir(){

     for(int j=m-1;j>0;j--){
        for(int i=1;i<=n-1;i++){
            cout<<W[j][i]<<"  ";
        }
        cout<<endl;
    }
}


// Función para guardar la matriz W[i][j]
void EcEliptica::guardar(){

    // Se crea el archivo para almacenar los datos
    string data = "DataPoissonEc.txt";
    ofstream outFile;
    outFile.open(data.c_str(), std::ofstream::out);


     for(int j=m-1;j>0;j--){
        for(int i=1;i<=n-1;i++){
            
            outFile << W[j][i] << "\t";
        }
        outFile << "\n";
    }
}

// Función tabla de error, evalua la tabla de error

void EcEliptica::error(double(*u)(double, double)){

    int e=10;

    cout << endl << left  << "i" << setw( e )<<"j"<<setw(e)<<"x" <<setw(e)<<"y"<<setw(e)
       << "w" << setw(e)<<"u"<<setw(e)<<"|w-u|" << endl << fixed << showpoint;

    for(int j=1;j<=m-1;j++){
        for(int i=1;i<=n-1;i++){
        cout << left << i << setw( e )<< j <<setw(e)<<x[i] <<setw(e)<<y[j]<<setw(e)
            << W[j][i] << setw(e)<<u(x[i],y[j])<<setw(e)<<abs(W[j][i]-u(x[i],y[j])) << endl;
        }
        cout<<endl;
    }

}