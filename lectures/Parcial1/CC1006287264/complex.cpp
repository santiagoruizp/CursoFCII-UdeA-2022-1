#include<iostream>

using namespace std;

class Complex{

private:

    int real;

    int imag;

public:    

     void setvalue()

    {

        cin>>real;

        cin>>imag;

    }
    void getrealvalue(Complex c1)

    {

        cout<< "\nParte real del primer numero" <<c1.real;

        

    }
    void getivalue(Complex c1, Complex c2)

    {

        cout<< "Parte imaginaria del primer numero" <<c1.imag;

        

    }

	// Función para impresión de los números complejos

    void display()

    {

        cout<<real<<"+"<<imag<<"i"<<endl;

    }

	// Función para sumar 2 numeros complejos 

 

    void sum(Complex c1, Complex c2)

    {

        real=c1.real+c2.real;

        imag=c1.imag+c2.imag;

    }
    void resta(Complex c1, Complex c2)
    {
         real=c1.real-c2.real;
         imag=c1.imag-c2.imag;

    }

    };

int main()

    {

        Complex c1,c2,c3,c4;

        cout<<"Ingresa la parte real e imaginaria del primer numero"<<endl;

        c1.setvalue();

        cout<<"Ingresa la parte real e imaginaria del segundo numero"<<endl;
        
        c1.getrealvalue(c1); 
        
        c2.setvalue();

        cout<<"Suma y resta de dos numeros complejos: "<<endl;

        c3.sum(c1,c2);
        c4.resta(c1,c2);

        c3.display();
        c4.display();

    return 0;
    // Sí se puede programar, al menos la multiplicación 
    }   