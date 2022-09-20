#include <iostream>
#include <iomanip>

#include "./Cuenta.h"
#include "./CuentaAhorros.h"
#include "./CuentaCheque.h"

int main() {

//    Se pone la impresion como puntos flotates con 2 digitos decimales
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "PRUEBAS PARALA CLASE BASE Cuenta: " << std::endl;
    std::cout << "\n";

    //   Prueba para ver que pasa si se crea una cuenta con saldo negativo, debe arrojar mensaje dele error
    try {
        std::cout << "Prueba para ver que pasa si se crea una cuenta con saldo negativo:" << std::endl;
        Cuenta cuenta = Cuenta(-10);
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se crea una cuenta con saldo cero
    try {
        std::cout << "Prueba para ver que pasa si se crea una cuenta con saldo cero:" << std::endl;
        Cuenta cuenta = Cuenta(0.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se crea una cuenta con saldo positivo
    try {
        std::cout << "Prueba para ver que pasa si se crea una cuenta con saldo positivo:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa abono negativo
    try {
        std::cout << "Prueba para ver que pasa si se pasa abono negativo:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.abonar(-10000);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa abono cero
    try {
        std::cout << "Prueba para ver que pasa si se pasa abono cero:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.abonar(0.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa abono positivo
    try {
        std::cout << "Prueba para ver que pasa si se pasa abono positivo:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.abonar(100000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa cargo negativo
    try {
        std::cout << "Prueba para ver que pasa si se pasa cargo negativo:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.cargar(-100000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa cargo cero
    try {
        std::cout << "Prueba para ver que pasa si se pasa cargo cero:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.cargar(0.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa cargo positivo menor al saldo
    try {
        std::cout << "Prueba para ver que pasa si se pasa cargo positivo menor al saldo:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.cargar(100000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa cargo positivo igual al saldo
    try {
        std::cout << "Prueba para ver que pasa si se pasa cargo positivo igual al saldo:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.cargar(1000000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para ver que pasa si se pasa cargo positivo mayor al saldo
    try {
        std::cout << "Prueba para ver que pasa si se pasa cargo positivo mayor al saldo:" << std::endl;
        Cuenta cuenta = Cuenta(1000000.0);
        cuenta.cargar(10000000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "----------------------------------------------------------------------";
    std::cout << "\n";
    std::cout << "\n";

    std::cout << "PRUEBAS PARALA CLASE HIJA CuentaAhorros: " << std::endl;
    std::cout << "\n";

    //   Prueba para ver que pasa si se crea una cuenta con saldo negativo, debe arrojar mensaje dele error
    try {
        std::cout << "Prueba para ver que pasa si se crea una cuenta con saldo negativo:" << std::endl;
        CuentaAhorros cuenta = CuentaAhorros(-10, 0.1);
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //    Prueba para calcular intereses y abonarlos
    try {
        std::cout << "Prueba para calcular intereses y abonarlos:" << std::endl;
        CuentaAhorros cuenta = CuentaAhorros(1000000.0, 0.005);
        std::cout << "El interes de la cuenta es: "<< cuenta.calcularIntereses() << std::endl;
        cuenta.abonar(cuenta.calcularIntereses());
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }


    std::cout << "----------------------------------------------------------------------";
    std::cout << "\n";
    std::cout << "\n";

    std::cout << "PRUEBAS PARALA CLASE HIJA CuentaCheque: " << std::endl;
    std::cout << "\n";

    //   Prueba para ver que pasa si se crea una cuenta con saldo negativo, debe arrojar mensaje dele error
    try {
        std::cout << "Prueba para ver que pasa si se crea una cuenta con saldo negativo:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(-10, 1000);
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para abonar cantidad negativa
    try {
        std::cout << "Prueba para abonar cantidad negativa:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.abonar(-100000);
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para abonar cero
    try {
        std::cout << "Prueba para abonar cero:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.abonar(0);
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para abonar cantidad positiva
    try {
        std::cout << "Prueba para abonar cantidad positiva:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.abonar(100000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para cargar cantidad negativa
    try {
        std::cout << "Prueba para cargar cantidad negativa:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.cargar(-100000);
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para cargar cero
    try {
        std::cout << "Prueba para cargar cero:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.cargar(0);
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para cargar cantidad positiva menor que saldo
    try {
        std::cout << "Prueba para cargar cantidad positiva menor que el saldo:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.cargar(100000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para cargar cantidad positiva igual que el saldo
    try {
        std::cout << "Prueba para cargar cantidad positiva igual que el saldo:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.cargar(1000000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para cargar cantidad positiva mayor que el saldo
    try {
        std::cout << "Prueba para cargar cantidad positiva mayor que el saldo:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.cargar(100000000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    //   Prueba para dejar cuenta en ceros
    try {
        std::cout << "Prueba para dejar cuenta en ceros:" << std::endl;
        CuentaCheque cuenta = CuentaCheque(1000000, 1000);
        cuenta.cargar(999000.0);
        std::cout << "El saldo de la cuenta es: "<< cuenta.getSaldoCuenta() << std::endl;
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }
    std::cout << "\n";

    return 0;
}
