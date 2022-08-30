#ifndef CUENTA_H
#define CUENTA_H

class Cuenta   //clase base
{
 public:
    Cuenta( double ); // Constructor que inicializa los datos miembros. Representa el saldo de la cuenta con valor tipo double
    void abonar( double ); // Suma monto al saldo actual
    bool cargar( double ); // Retira dinero de la cuenta. Asegura que el monto a cargar no exceda el saldo de la cuenta
    double getSaldo(); // Devuelve el saldo actual
    void establecerSaldo( double ); // Establece el saldo de la cuenta
private:
    double Saldo; // 

}; // final de la clase base

#endif
