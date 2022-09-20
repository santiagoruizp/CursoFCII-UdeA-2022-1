#ifndef C_BANCARIA
#define C_BANCARIA

//Clase padre Cuenta
class Cuenta{
    public: 
    Cuenta(double);
    bool abonar(double);
    bool cargar(double);
    double getSaldo();
    void opciones();


    private: 
    double saldo;

};
//clase heredada cuenta de ahorros
class CuentaAhorros : public Cuenta{
    public:
        CuentaAhorros(double , double);
        double calcularInteres();
        void opciones();

    private:
    double interes;

};


//clase heredada cuenta de cheques
class CuentaCheques : public Cuenta{
    public:
        CuentaCheques(double , double);
        void abonar(double);
        void cargar(double);
        void opciones();

    private:
    double cuota;

};
#endif