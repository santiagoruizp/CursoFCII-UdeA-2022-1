#include<iostream>
using namespace std;
class complex{
public:
    complex(double,double);//Const.
    void sum(double,double);
    void substraction(double,double);
    void asingdata();
    void getrealpart();
    void getimpart();
    void print();
    void product(double,double);
    void division(double,double);

private:
    double Impart;
    double Repart;
};