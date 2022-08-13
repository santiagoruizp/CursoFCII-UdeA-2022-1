#include <string> 
using std::string;
    
    
// clase 
class NumerosComplejos
{
    public:
    NumerosComplejos(); 
    
    void asignarDatos(); 
    double verificarDatos();
    void asignarParteReal(double);
    void asignarParteImaginaria(double);
    double obtenerParteReal(); 
    double obtenerParteImaginaria();
    void impresionResult();

    // Operaciones entre complejos
    NumerosComplejos sumaComplejos(NumerosComplejos, NumerosComplejos);
    NumerosComplejos restaComplejos(NumerosComplejos, NumerosComplejos);
    NumerosComplejos multiplicaComplejos(NumerosComplejos, NumerosComplejos);
    NumerosComplejos conjugado(NumerosComplejos);
    NumerosComplejos divideComplejos(NumerosComplejos, NumerosComplejos);

    
    private:
    double parteImaginaria;
    double parteReal;
  
};