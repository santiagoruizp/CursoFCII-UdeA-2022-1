
#include "CuentaAhorros.h"
#include "CuentaCheques.h"

int main()
{

    // ---------------------------------
    // -------- CUENTA DE AHORROS ------
    // ---------------------------------
    std::cout << "\n -------- CUENTA DE AHORROS -------- "<< std::endl;
    CuentaAhorros cuentaAhorros = CuentaAhorros(800, 0.02);

    // Abono de intereses
    double interes = cuentaAhorros.calcularInteres();
    cuentaAhorros.abonar(interes);

    // Abono 
    cuentaAhorros.abonar(200);

    // Retiro
    cuentaAhorros.cargar(500);

    // Retiro mayor al saldo
    cuentaAhorros.cargar(1000);


    // ---------------------------------
    // -------- CUENTA CHEQUES ---------
    // ---------------------------------
    std::cout << "\n -------- CUENTA CHEQUES -------- "<< std::endl;
    CuentaCheques cuentaCheques = CuentaCheques(1000, 10);

    // Abono 
    cuentaCheques.abonar(100);

    // Retiro mayor al saldo más lo que cuesta el movimiento
    cuentaCheques.cargar(1100);

    // Retiro
    cuentaCheques.cargar(1000);

    
    return 0;
}
