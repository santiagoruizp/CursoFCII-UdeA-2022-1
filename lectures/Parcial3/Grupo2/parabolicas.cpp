#include "parabolicas.h"

using namespace std;

Parabolicas::Parabolicas( string name )
{
cout <<"Ecuaciones diferenciales parciales parabolicas\n"<<endl;
}

double Parabolicas::funcion(const double x){
    const double PI = 3.1416;
    return sin(PI*x);
}


void Parabolicas::regresivas(const double l1, const double m1 ,const double N1 ,const double T1, const double alpha ){

    double x;
    double t; 
    
    int m = m1;
    int N = N1;
    
    double L[m];
    double U[m];
    double W[m];
    double Z[N];
    double X[m];
    
    // condiciones iniciales
    W[m] = 0;
    W[0] = 0;
    
    X[m] = l1;
    X[0] = 0;
    
    //STEP 1
    double h = l1/m1;
    double k = T1/N1;
    double lambda = k*(alpha*alpha)/(h*h);
    
    cout << "h = "<< h << endl;
    cout << "k = "<< k << endl;
    cout << "lambda = " << lambda <<endl;
    cout << "-----------------------------"<<endl;
    
    //STEP 2
    for (int i = 1; i <= (m-1); ++i) {
        W[i] = funcion(i*h);
    }
    
    //STEP 3
    L[1] = 1+2*lambda; //posicion 0 de L
    U[1] = -1*lambda/L[1];
    
    //STEP 4
    for (int i = 2; i <= (m-2); ++i) {
        L[i] = 1+2*lambda+lambda*U[i-1];
        U[i] = -1*lambda/L[i];
    }
    
    //STEP 5
    L[m-1] = 1+2*lambda+lambda*U[m-2];
    
    for (int i = 1; i <= m-1; ++i) {
        x=i*h;
        X[i] = x;
    }
    
    cout<<fixed;
    cout <<"Time|Posicion|   ";
    for ( int i = 0; i <= m; i++ ){
    cout << X[ i ]<<setw(11);
    }  
    cout<<"\n";
    
    //STEP 6
    for (int j = 1; j <= N; j++) {
        
        //STEP 7 
        t = j*k;

        Z[1]=W[1]/L[1];

        //STEP 8
        for (int i = 2; i <= m-1; ++i) {
            Z[i] = (W[i]+lambda*Z[i-1])/L[i];   
        }

        //STEP 9
        W[m-1] = Z[m-1];

        //STEP 10
        for (int i = m-2; i >= 1; i--) {
            W[i] = Z[i]-U[i]*W[i+1];
        }

        //STEP 11
        
        cout << t<<setw(17); //imprime tiempo
        for ( int i = 0; i <= m; i++ ){
            cout << W[ i ]<<setw(11);
            
        }
	cout<<"\n";
    }
    
}

void Parabolicas::crankNicolson(const double l1, const double m1, const double N1, const double T1, const double alpha){

    double x;
    double t; 
    
    int m = m1;
    int N = N1;
    
    double L[m];
    double U[m];
    double W[m];
    double Z[N];
    double X[m];
    
    // condiciones iniciales
    W[m] = 0;
    W[0] = 0;
    
    X[m] = l1;
    X[0] = 0;
    
    //STEP 1
    double h = l1/m1;
    double k = T1/N1;
    double lambda = k*(alpha*alpha)/(h*h);
    
    cout << "h = "<< h << endl;
    cout << "k = "<< k << endl;
    cout << "lambda = " << lambda <<endl;
    cout << "-----------------------------"<<endl;
    
    //STEP 2
    for (int i = 1; i <= (m-1); ++i) {
        W[i] = funcion(i*h);
    }
    
    //STEP 3
    L[1] = 1+lambda; //posicion 0 de L
    U[1] = -1*lambda/(2*L[1]);
    
    //STEP 4
    for (int i = 2; i <= (m-2); ++i) {
        L[i] = 1+lambda+(lambda*U[i-1]/2);
        U[i] = -1*lambda/(2*L[i]);
    }
    
    //STEP 5
    L[m-1] = 1+lambda+(lambda*U[m-2]/2);
    
    for (int i = 1; i <= m-1; ++i) {
        x=i*h;
        X[i] = x;
    }
    
    cout<<fixed;
    cout <<"Time|Posicion|   ";
    for ( int i = 0; i <= m; i++ ){
    cout << X[ i ]<<setw(11);
    }  
    cout<<"\n";
    
    //STEP 6
    
    for (int j = 1; j <= N; j++) {
        
        //STEP 7 
        
        t = j*k;
        
        Z[1]=((1-lambda)*W[1]+(lambda*W[2]/2))/L[1];

        //STEP 8
        for (int i = 2; i <= m-1; ++i) {
            Z[i]=((1-lambda)*W[i]+(lambda*(W[i+1]+W[i-1]+Z[i-1])/2))/L[i];   
        }

        //STEP 9
        W[m-1] = Z[m-1];

        //STEP 10
        for (int i = m-2; i >= 1; i--) {
            W[i] = Z[i]-U[i]*W[i+1];
        }

        //STEP 11
        
        cout << t<<setw(17); //imprime tiempo
        for ( int i = 0; i <= m; i++ ){
            cout << W[ i ]<<setw(11);
            
        }
	cout<<"\n";
	
    }
      
}


