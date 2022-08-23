#ifndef FECHA_H
#define FECHA_H

using namespace std;
class Fecha
{
    public:

        Fecha( int = 1, int = 1, int = 3000 );
        void imprimir() const; 
        void diaSig() ; 
        void establecerAnio(int) ; 
        void establecerMes(int) ;
        void establecerDia(int) ;

    private:
        int dia; 
        int mes; 
        int anio; 

};

Fecha::Fecha( int dd, int mm, int aa ){
    establecerAnio(aa);
    establecerMes(mm);
    establecerDia(dd);
}

void Fecha::imprimir() const
{
  cout << dia << '/' << mes << '/' << anio;
}


void Fecha::diaSig() 
{
  int diasCadaMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if ( mes == 2 && ( anio % 400 == 0 || ( anio % 4 == 0 && anio % 100 != 0 ) ) )
  { 	
    diasCadaMes[2] = 29;
  }

  
  if ( dia < diasCadaMes[ mes ] )
  {
  dia += 1;
  cout<<"\ndia siguiente: \n";
  imprimir();
  }

  else if ( dia == diasCadaMes[ mes ] && mes == 12)
  {
  dia = 1;
  mes = 1;
  anio += 1;
  cout<<"\ndia siguiente: \n";
  imprimir();
  }  
}

void Fecha::establecerAnio(int anio_)
{
if ( anio_ > 0 && anio_ <= 3500 ) 
    anio = anio_;
  else
    {
      anio = 2022; // se establece
      cout << "año invalido "<< anio_ << "\n";
    }
}

void Fecha::establecerMes(int mm_)
{
if ( mm_ > 0 && mm_ <= 12 ) 
    mes = mm_;
  else
    {
      mes = 1; 
      cout << "Mes invalido (" << mm_ << ")\n";
    }
}

void Fecha::establecerDia(int dia_)
{
  static const int diasCadaMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if ( dia_ > 0 && dia_ <= diasCadaMes[ mes ] )
    dia = dia_;

  else if ( mes == 2 && dia_ == 29 && ( anio % 400 == 0 ||( anio % 4 == 0 && anio % 100 != 0 ) ) )
  { 	
    dia = dia_; }

}
         
#endif