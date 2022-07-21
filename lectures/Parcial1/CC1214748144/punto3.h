class Complejo 
{
    private: 
        double a1;      //parte real del primer número     
        double b1; 	//parte imaginaria del primer número
    public:
        void asignarDatos(double, double);
        double obtenerParteReal();
        double obtenerParteImaginaria();
        void suma( double, double); // el argumento significa que la función depende un objeto de la misma clase. 
        void resta(double, double ); 
        void multiplicacion(double, double);
        void division(double, double);
        void mostrar(double, double); 
        Complejo(double,double);
};
