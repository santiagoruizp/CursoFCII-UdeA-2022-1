#ifndef COMISION_H
#define COMISION_H

#include <string> 
using namespace std;

class Cuenta
{
 public:
  Cuenta(  double =0.0 );
 
  void setsaldo( double ); 
  double getsaldo() const;
  
  void abonar( double ); 
  double getabono() const;
  
  void cargar( double ); 
  double getcarga() const;


  
  
  void imprimir() const;

  private:
  
  double abonos;
  double cargas;
  double saldot; 
   
};

#endif