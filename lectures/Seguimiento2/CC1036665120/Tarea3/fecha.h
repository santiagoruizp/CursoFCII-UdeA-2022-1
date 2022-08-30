
#include <iostream>

class fecha
{
private:
    int dia;
    int mes;
    int anio;


public:
    fecha( int , int , int );
    ~fecha();

    void imprimir() const;

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int &);
    void setMes(int &);
    void setAnio(int &);

    int comprobarDia( int ) const;
    int comprobarMes( int ) const;
    int comprobarAnio( int ) const;

    bool validarFeb29( int ) const;
};

