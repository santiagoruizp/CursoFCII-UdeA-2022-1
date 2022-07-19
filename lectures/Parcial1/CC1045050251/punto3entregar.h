class Complejo{
    private:
        double real,imaginaria;
    
    public:
        Complejo(double,double);
        void asignarDatos(double,double);
        double obtenerParteReal();
        double obtenerParteImaginaria();
        void suma(double,double);
        void resta(double,double);
        void multiplicacion(double,double);
        void mostrar(double,double);
};
