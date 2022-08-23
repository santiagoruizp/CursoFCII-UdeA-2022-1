//
// Created by kevin on 21/08/22.
//

#ifndef FECHA_FECHA_H
#define FECHA_FECHA_H

class Fecha
{
public:
    Fecha( int mes = 0, int dia = 0, int anio = 0); // constructor predeterminado
    void imprimir() const;
    void diaSig();
    void setMes(int mes);
    void setDia(int dia);
    void setAnio(int anio);
    void setFecha(int m, int d, int y);

private:
    int mes;
    int dia;
    int anio;
//    Estas dos funciones son utilitarias
    bool esBisiesto(int anio);
    int diasPorMes(int mes, int anio);
};



#endif //FECHA_FECHA_H
