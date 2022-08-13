#include<iostream>

using namespace std;

class perfect_n
{
int n;
int c;

public:
    
    perfect_n()
    {
        cout<<"Ingresar numero a evaluar:";
        cin>>n;
        
    }
    int perfect(int  );
    double evaluate_n( int n );
    
    void printDivisors(int k);

    void display()
    {
        cout<<evaluate_n( n);
    }
    
};
