#include "Integracion.h"

float quadr(float x){

   return x*x;

}

float g(float x){

   return x*x*x + 1;

}

float h(float x){

   return log(x);

}

int main(){

   Integracion test1(&quadr, 0, 1);
   float Trap1 = test1.TrapezoidIntegral();
   float Simp1 = test1.SimpsonIntegral(); 
   float realval1 = 1.0/3.0, errt1 = 100.0*abs(Trap1-realval1), errs1 = 100.0*abs(Simp1-realval1);
   cout<<"Prueba con la función x² entre 0 y 1"<<endl;
   cout<<"Regla del trapecio: "<<setprecision(15)<<Trap1<<setw(30)<<"Error porcentual: "<<errt1<<endl;
   cout<<"Regla de Simpson: "<<setprecision(15)<<Simp1<<setw(30)<<"Error porcentual: "<<errs1<<endl;
   cout<<endl;
   
   Integracion test2(&g, 0, 2);
   float Trap2 = test2.TrapezoidIntegral();
   float Simp2 = test2.SimpsonIntegral(); 
   float realval2 = 6.0, errt2 = 100.0*abs(Trap2-realval2), errs2 = 100.0*abs(Simp2-realval2);
   cout<<"Prueba con la función x³+1 entre 0 y 2"<<endl;
   cout<<"Regla del trapecio: "<<setprecision(15)<<Trap2<<setw(30)<<"Error porcentual: "<<errt2<<endl;
   cout<<"Regla de Simpson: "<<setprecision(15)<<Simp2<<setw(30)<<"Error porcentual: "<<errs2<<endl;
   cout<<endl;
   
   Integracion test3(&h, 1, 2);
   float Trap3 = test3.TrapezoidIntegral();
   float Simp3 = test3.SimpsonIntegral(); 
   float realval3 = 0.3862943611198906, errt3 = 100.0*abs(Trap3-realval3), errs3 = 100.0*abs(Simp3-realval3);
   cout<<"Prueba con la función log(x) entre 1 y 2"<<endl;
   cout<<"Regla del trapecio: "<<setprecision(15)<<Trap3<<setw(30)<<"Error porcentual: "<<errt3<<endl;
   cout<<"Regla de Simpson: "<<setprecision(15)<<Simp3<<setw(30)<<"Error porcentual: "<<errs3<<endl;
   cout<<endl;

   return 0;

}


