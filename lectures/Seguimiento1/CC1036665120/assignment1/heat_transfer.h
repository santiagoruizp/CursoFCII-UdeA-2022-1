
#include <string> 
    
using std::string;
    
// clase 
class HeatTransfer
{
 public :
  HeatTransfer(); 
  float stablishArea();
  float stablishTempSurface();
  float stablishTempEnv(); 
  float calcHeatTransfer(float area, float temp_surf, float temp_env);
  void mostrarMensaje(float q);
};