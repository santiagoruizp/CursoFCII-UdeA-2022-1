#ifndef FECHA_H
#define FECHA_H

//  definicion de la clase fecha

class Fecha
{
    public:

    explicit Fecha(int =1, int = 1, int = 1900 ); // constructor predeterminado
    void diaSig(); // incrementa la Fecha en 1
    void imprimir(); // funcion imprimir
    Fecha &establecerFecha(int, int, int); // establece dia, mes, año
    Fecha &establecerDia(int); // establece dia
    Fecha &establecerMes(int); // establece mes
    Fecha &establecerAnio(int); // establece año
    unsigned int obtenerMes() const; // devuelve mes
    unsigned int obtenerDia() const; // devuelve dia
    unsigned int obtenerAnio() const; // devuelve  año
    

    private:
    unsigned int mes; // va de 1-12
    unsigned int dia; //va de 1-31 para alhunos mese, para otros no
    unsigned int anio;  // año
    unsigned int diasMes(); // dias de cada mes
    
    bool AnioBisiesto();  // año bisiesto
}; //final de la clase

#endif