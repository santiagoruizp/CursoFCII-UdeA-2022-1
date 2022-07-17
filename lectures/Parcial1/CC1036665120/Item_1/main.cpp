// ---------------------------------------------------------------
// -------- Realizar intregales numéricas usando  ----------------
// -------- “LA REGLA TRAPEZOIDAL" y “LA REGLA DE SIMPSON" -------
// ---------------------------------------------------------------

#include<iostream>
#include<cmath>
using namespace std;


// --------------------------------------------
// Función a Integrar
// --------------------------------------------
float funcToIntegrate(float x){
    
    return sqrt(pow(x, 2) + sin(x));
}


// --------------------------------------------
// Ejecuta: Composite Simpson’s Rule
// --------------------------------------------
double simpsonIntegral(int n, float a, float b){

    float h = ( b - a ) / n;

    // Partes de la aproximación a la integral
    float I_1 = funcToIntegrate(a) + funcToIntegrate(b);
    float I_2 = 0;
    float I_3 = 0;
    
    // Recorre los intervalos y va sumando 
    for (int i = 1; i < n; i++)
    {
        // valor de x a lo largo del intervalo
        float x = a + i*h;

        // Verificar si el índice es par 
        if (i%2==0){
            I_2 += funcToIntegrate(x);
        }else{
            I_3 += funcToIntegrate(x);
        }
        
    }

    // Aproximación a la integral 
    double I = h*(I_1 + 2*I_2 + 4*I_3)/3;

    return I;
    
}


// --------------------------------------------
// Ejecuta: Composite Trapezoidal rule
// --------------------------------------------
double trapezoidalIntegral(int n, float a, float b){

    float h = ( b - a ) / n;

    // Partes de la aproximación a la integral
    float I_1 = funcToIntegrate(a) + funcToIntegrate(b);
    float I_2 = 0;
    
    // Recorre los intervalos y va sumando 
    for (int i = 1; i < n; i++)
    {
        // valor de x a lo largo del intervalo
        float x = a + i*h;

        I_2 += funcToIntegrate(x); 
        
    }

    // Aproximación a la integral 
    double I = h*(I_1 + 2*I_2)/2;

    return I;

}


// --------------------------------------------
// Verificación de los números ingresados
// --------------------------------------------
bool verifyNumbers(int n){

    bool result = true;
    if (n%2 != 0)
    {
        cout<<"El número n debe ser par"<<endl;
        result = false;
    }

    return result;
}


// --------------------------------------------
float verifyType(){

    float num=0;
    cin >> num;

    while (cin.fail())
    {
        if (cin.fail())
        {
            cout << "Debes ingresar un número." << endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
        cin >> num;
    }

    return num;
}


// --------------------------------------------
int main(){

    float a = 0;
    float b = 0;
    int n = 0;

    // Ingresar datos y verificar que sean números
    cout << "Ingresa el límite inferior de la integral:  ";
    a = verifyType();
    cout << "Ingresa el límite superior de la integral:  ";
    b = verifyType();
    cout << "Ingresa la precisión:  ";
    n = verifyType();

    // n determina la cantidad de términos de la sumatoria y debe ser par 
    bool verify = verifyNumbers(n);

    if (verify)
    {
        double result_trapez = trapezoidalIntegral(n, a, b);
        double result_simp = simpsonIntegral(n, a, b);


        cout << "La integral con la regla compuesta de Simpson es " << result_simp << endl;
        cout << "La integral con la regla compuesta Trapezoidal es " << result_trapez << endl;

    }
    
    return 0;

}