//
// Created by kevin on 16/07/22.
//

#ifndef PUNTO3PARCIAL_COMPLEJO_H
#define PUNTO3PARCIAL_COMPLEJO_H


#include <ostream>

class Complejo {
private:
    double parteReal{};
    double parteImaginaria{};

public:
    Complejo(double parteReal, double parteImaginaria);

    Complejo();

    void asignarDatos(double parteReal, double parteImaginaria);

    double obtenerParteReal() const;

    double obtenerParteImaginaria() const;

    double norma() const ;

    void imprimirComplejo() const;

};

class AritmeticaCompleja:  public Complejo{
public:
    AritmeticaCompleja();

    static Complejo sumarDosComplejos(Complejo c1, Complejo c2);

    static Complejo restarDosComplejos(Complejo c1, Complejo c2);

    static Complejo multiplicarDosComplejos(Complejo c1, Complejo c2);

};

#endif //PUNTO3PARCIAL_COMPLEJO_H
