
#ifndef FECHA_H
#define FECHA_H

class Fecha{

   public:
      // Constructor con valores predeterminados
      Fecha( int = 1, int = 1, int = 1 ); 
      // Imprime la fecha en formato día/mes/año
      void imprimir() const; 
      // Función de día siguinete
      void diaSig(void) const;
      // Destructor 
      ~Fecha(); 
 
   private:
      // 1-12 (Enero-Diciembre)
      int mes; 
      // 1-31 con base en el mes
      int dia; 
      // Cualquier año desde el 0 AD
      int anio; 
      // Función utilitaria para comprobar si el dia es apropiado para mes y anio
      int comprobarDia( int ) const;
      // Arreglo de los días por mes constante y static
      static const int diasPorMes[13];
};
#endif
