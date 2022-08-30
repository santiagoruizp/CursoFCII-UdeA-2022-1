#ifndef FECHA_H
#define FECHA_H
// definición de la clase Fecha

class Fecha
{
 public:
  Fecha( int = 1, int = 1, int = 2000 ); // constructor predeterminado
  void imprimir() const;// imprime la fecha
  ~Fecha(); // se proporciona para confirmar el orden de destrucción
  void diaSig(); //aumenta la fecha en un día
  
 private:
  int mes;
  int dia;
  int anio;

  // función utilitaria para comprobar si el dia es apropiado para mes y anio
int comprobarDia( int ) const;
}; 

#endif