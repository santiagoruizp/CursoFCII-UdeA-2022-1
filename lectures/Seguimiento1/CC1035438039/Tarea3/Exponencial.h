//
// Created by kevin on 22/06/22.
//

#ifndef EXPONENCIAL_EXPONENCIAL_H
#define EXPONENCIAL_EXPONENCIAL_H


class Exponencial {
private:
    double x;
    int N;

public:
    Exponencial(double x, int n);

    double calcularExponencial();

    double getX() const;

    void setX(double x);

    int getN() const;

    void setN(int n) ;

    int calcularFactorial(int n);

    void getValor();
};


#endif //EXPONENCIAL_EXPONENCIAL_H
