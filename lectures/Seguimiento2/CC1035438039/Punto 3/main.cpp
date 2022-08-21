#include <iostream>
#include "Fecha.h"

int main() {

    try{
        Fecha fecha(1,1,2011);
        fecha.imprimir();

    //    Prueba para ver si la fecha avanza en un dia
        try {
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

    //    Prueba para ver si en el dia final del mes el dia vuelve a 1 y el mes pasa al siguiente
        try {
            fecha.setDia(31);
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

    //  Prueba para ver si en el dia final del año; el dia vuelve a 1, el mes vuelve a 1 y el año pasa al siguiente
        try {
            fecha.setMes(12);
            fecha.setDia(31);
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

    //    Prueba para año bisiesto con, es decir el mes 2 tiene solo 28 dias.
    //    Debe arrojar error indicando que la cantidad de dias es mayor a la que permite el mes
        try{
            fecha.setAnio(2000);
            fecha.setMes(2);
            fecha.setDia(29);
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

    //  Prueba para ver si en los años bisiestos el mes de febrero funciona bien
        try{
            fecha.setAnio(2000);
            fecha.setMes(2);
            fecha.setDia(28);
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

        //  Prueba para ver si en los años no bisiestos el mes de febrero funciona bien
        try{
            fecha.setAnio(2001);
            fecha.setMes(2);
            fecha.setDia(29);
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

    //  Prueba para ver si en los años no bisiestos el mes de febrero funciona bien
        try{
            fecha.setAnio(2001);
            fecha.setMes(2);
            fecha.setDia(29);
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

        //  Prueba para ver el error en un mes mayor a 12
        try{
            fecha.setAnio(2001);
            fecha.setMes(13);
            fecha.setDia(29);
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }


        //  Prueba para ver el error en un mes menor a 1
        try{
            fecha.setAnio(2001);
            fecha.setMes(0);
            fecha.setDia(29);
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }

        //  Prueba para ver el error en un dia menor a 1
        try{
            fecha.setAnio(2001);
            fecha.setMes(1);
            fecha.setDia(0);
            fecha.diaSig();
            fecha.imprimir();
        }catch (const char* msg){
            std::cout<< msg << std::endl;
        }
    }catch (const char* msg){
        std::cout<< msg << std::endl;
    }

    return 0;
}
