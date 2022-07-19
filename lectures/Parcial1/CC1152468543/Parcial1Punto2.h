#include <iostream>
#include <stdlib.h>
using namespace std;

class complejo{
	private:
	float parteImaginaria;
	float parteReal;
	
	public:
	
	complejo(float,float);
	
	float obtenerParteReal();
	float obtenerParteImaginaria();
	float suma();
}
