#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include "fecha.h"

class fechaSiguiente : public fecha
{
private:
    int diaS;
    int mesS;
    int anioS; 

public:
    fechaSiguiente( const int &, const int &, const int & );
    ~fechaSiguiente();
    void setDia( const int );
    void setMes( const int );
    void setAnio( const int );

    void diaSig( );
    void imprimir() const;
};
#endif

