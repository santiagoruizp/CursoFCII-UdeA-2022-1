#include <iostream>


class Cuenta
{
private:
    double saldo;
    double validarSaldo(double &);



public:
    Cuenta(double);
    ~Cuenta();

    void abonar(double);
    void cargar(double);
    double getSaldo();
};