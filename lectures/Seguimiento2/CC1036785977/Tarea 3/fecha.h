#ifndef FECHA_H
#define FECHA_H

class Fecha
{
public:
Fecha( int = 1, int = 1, int = 2000 );
 
void imprimir() const; // imprime la fecha en formato dia/mes/año
void diaSig() ; // imprime el dia siguiente en formato dia/mes/año
                // no es constante por que hace cambios 
void setAnio(int) ; 
void setMes(int) ;
void setDia(int) ;

private:
int dia; // 1-31 con base en el mes
int mes; // 1-12 (Enero-Diciembre)
int anio; // cualquier año
 
};

#endif
