#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <vector>
#include <algorithm>  
#include <cmath>

#include "Parcial2_2.h"

int main(){
	DatosHoteles hotel("Desktop/Computacional/Seguimiento 2/camas_hotel.txt");
	hotel.nuevaListaSinDuplicados();
	hotel.impr();
	hotel.estadistico();
	hotel.seleccionar(20);
	cout<<hotel.contar(20210101)<<endl;
	return 0;
}
