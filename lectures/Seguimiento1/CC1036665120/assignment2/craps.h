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
  float calcularDinero(float estado, float apuesta);
  void mostrarMensaje(int estado);
  bool preguntaSeguir();
};