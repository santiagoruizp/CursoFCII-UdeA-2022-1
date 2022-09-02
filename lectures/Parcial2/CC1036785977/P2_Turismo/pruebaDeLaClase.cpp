#include "turismo.h"
using namespace std;

int main()
{
Turismo prueba( "camas_hotel.txt" );
prueba.leeProcesa(prueba.getName());
prueba.nuevaListaSinDuplicados();
prueba.seleccionar(16);
prueba.estadistico();
prueba.contar(1,1,2022);
prueba.eliminarHotel(16);
return 0;
}
