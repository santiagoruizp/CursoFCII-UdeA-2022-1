#include<iostream>

using namespace std;

class expo
{
private:
    int n;
     
    double x;
    

public:
    
    expo()
    {
        cout<<"Enter the x value:";
        cin>>x;
        cout<<"Enter the precision:";
        cin>>n;
        
    }
    double fact(int  );
    double taylor(double , int );
    
    void display()
    {
        cout<<taylor(x,n);
    }
    
};
