
// Tarea 1 Alejandro Restrepo Giraldo CC: 1001389709

#include <iostream>
#include <iomanip>
#include <cmath>

#define h 8.7

using namespace std;


class HeatConv{

  public:
    
// ---------- Función para determinar el área

  float Area(int i){
    
    float a, b, l, w, A;

    switch(i){
  
      case 1:
        cout<<"The chosen shape is rectangular.\n\nEnter the width in meters: ";
        cin>>w;
        cout<<"Enter the length in meters: ";
        cin>>l;
        A = l*w;
        Ar = A;
        cout<<"\nThe area is "<<A<<" m²"<<endl<<endl;
        return A;
        break;   
       
        
      case 2:
        cout<<"The chosen shape is elliptical.\n\nEnter the semimajor axis in meters: ";
        cin>>a;
        cout<<"Enter the semiminor axis in meters: ";
        cin>>b;
        A = a*b*M_PI;  
        Ar = A;
        cout<<"\nThe area is "<<A<<" m²"<<endl<<endl;
        return A;
        break;  
      
        
      case 3:
        cout<<"\nThe shape is different. Enter the area in m²: ";
        cin>>A;
        cout<<"\nThe area is "<<A<<" m²"<<endl<<endl;
        Ar = A;
        return A;
        break;    
      
          
      default:
        cout<<"Invalid option. Restart the program.\n\n";
    }
  
  }
  
  
  
  
// ---------- Función para determinar el calor transmitido por unidad de area
    float HeatTransf(float Ts, float Ta){
    
      q = h*Ar*(Ts-Ta);
      cout<<"\nThe heat transferred per unit area is "<<q<<" watts/m²°C."<<endl<<endl;
      return q;
  }

  private:
    float q, Ar;
    
    
    
};



//-----------------------  Método main

int main(){


  cout<<"\n This program computes the heat transfer rate per unit area of a substance according to q = hA(Ts-Ta) given its area A, temperature Ts of such surface and the temperature of the ambient Ta. The convective heat transfer coefficient h used is 8.7 watts/m²°C.\n\n";
  
  
  cout<<"Please enter:\n"<<setw(20)<<"1: If the surface is rectangular.\n"<<setw(10)<<"2: If the surface is elliptical.\n"<<setw(10)<<"3: Other shape.\n\n";
      
  int j;
  cin>>j;

  HeatConv Test;
  Test.Area(j);
  
  float Ts, Ta;
  
  cout<<"\nEnter the temperature of the surface in °C: ";
  cin>>Ts;
  cout<<"Enter the temperature of the ambient in °C: ";
  cin>>Ta;
  
  Test.HeatTransf(Ts,Ta);
  
  
  
  cout<<"For the proposed excercise the heat transfer rate away from a chip in a computer’s console of rectangular shape with dimensions 0.02m X 0.02m, Ts = 44°C and Ta = 40°C is 0.01392 watts/m²°C."<<endl<<endl;
  
  return 0;

}



