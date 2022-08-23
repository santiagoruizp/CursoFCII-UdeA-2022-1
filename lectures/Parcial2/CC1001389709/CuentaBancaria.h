
#ifndef CUENTA
#define CUENTA

// Clase base 

class Cuenta{

    public:
        Cuenta(double);
        double getSaldo() const;
        void Abonar(double);
        void Cargar(double);

    private:
        double ValidacionSaldo(double);
        double saldo;
};



// Clases derivadas 

class CuentaAhorros: public Cuenta{
    public:
        CuentaAhorros(double, double);
        double CalcularInteres();

    private:
        double tasa;
};


class CuentaCheques: public Cuenta{

    public:
        CuentaCheques(double, double);
        void Abonar(double abono);
        void Cargar(double abono);

    private:
        double cuota;
};
#endif