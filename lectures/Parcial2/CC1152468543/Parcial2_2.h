#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <vector>
#include <algorithm>  
#include <cmath>

using namespace std;

class DatosHoteles {

	private:
		string nombre;
		vector <string> file;
		vector <string> modifile;
		
	public:
		DatosHoteles(string); //No le estoy poniendo cuidado a usar const, REVISAR.
		void leeProcesa(); //Metodo que lee el archivo y lo almacena en la memoria.
		void nuevaListaSinDuplicados();
		vector <string> seleccionar(int);
		void estadistico();
		int contar(int);
		void impr();

};
