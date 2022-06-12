
#include "heat_transfer.h"


/// este es el codigo que se va a ejecutar, el constructor 
int main()
{
HeatTransfer heat = HeatTransfer();
float area = heat.stablishArea();
float temp_surf = heat.stablishTempSurface();
float temp_env = heat.stablishTempEnv();
float q = heat.calcHeatTransfer(area, temp_surf, temp_env);
heat.mostrarMensaje(q);   
   
return 0; 
}