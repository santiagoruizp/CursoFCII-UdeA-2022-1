#include <string> 
    
using std::string;
    
// clase 
class JuegoCraps
{
 public :
  JuegoCraps(); 
  float dineroApostar();
  int tirarDados();
  float estadoJuego();
  float calcularDinero(float, float);
  void mostrarMensaje(int);
  bool preguntaSeguir();
};