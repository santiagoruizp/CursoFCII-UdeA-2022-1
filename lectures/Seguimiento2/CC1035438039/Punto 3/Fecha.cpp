//
// Created by kevin on 21/08/22.
//

#include "Fecha.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


Fecha::Fecha( int m, int d, int y ){
    setFecha(m, d, y);
}

void Fecha::diaSig() {
    int cantidadDias = diasPorMes(mes, anio);

    if(dia == cantidadDias){
        dia = 1;
        if(mes == 12){
            mes = 1;
            anio += 1;
        }else{
            mes += 1;
        }
    }else{
        dia += 1;
    }

}


// imprime la Fecha en el formato mm/dd/aaaa
void Fecha::imprimir() const{
    cout << mes << '/' << dia << '/' << anio << endl;
}

void Fecha::setMes(int mes) {
    if(mes<1 || mes>12){
        throw "El mes debe estar entre 1 y 12 (inclusive), entre Enero y Diciembre.";
    }
    Fecha::mes = mes;
}

void Fecha::setDia(int dia) {
    if (dia > diasPorMes(mes,anio) || dia<1){
        throw "Verifique su mes tenga la cantidad de dias que ingreso.";
    }
    Fecha::dia = dia;
}

void Fecha::setAnio(int anio) {
    Fecha::anio = anio;
}

void Fecha::setFecha(int m, int d, int y ){
    setAnio(y);
    setMes(m);
    setDia(d);
}


bool Fecha::esBisiesto(int anio){
//    funcion para saber si un año es bisiesto

//  La respuesta por defecto es negativa
    bool response = false;

//    si el año es multiplo de 4 es bisiesto
    if(anio % 4 == 0){
        response = true;
    }
    return response;
}

int Fecha::diasPorMes(int mes, int anio){
//    Funcion para saber cuantos dias tiene un mes de un año dado

//    La mayoria de los meses tienen 31 dias, esa sera la respuesta por defecto
    int response = 31;

//    Si el año es bisiesto y el mes es febrero, el mes tiene 28 dias
    if(esBisiesto(anio) && mes==2){
        response = 28;
    }

//        Si el año no es biciesto y el mes es febrero, el mes tiene 29 dias
    if(!esBisiesto(anio) && mes==2){
        response = 29;
    }

//  Los meses con 30 dias son, abril, junio, septiembre y noviembre
    std::vector<int> dias_30{4, 6, 9, 11};
    bool tiene_30 = (std::find(dias_30.begin(), dias_30.end(), mes) != dias_30.end());
//    Si el mes es alguno de esos entonces tiene 30 dias
    if (tiene_30){
        response = 30;
    }

    //    std::vector<int> dias_31{1, 3, 5, 7, 8, 10, 12};
//    bool tiene_31 = (std::find(dias_31.begin(), dias_31.end(), mes) != dias_31.end());
//    if(tiene_31){
//        return 31;
//    }

//  todos los demas meses tienen 31 dias, se puede realizar una doble comprobacion con el codigo de las lineas anteriores
    return response;
}