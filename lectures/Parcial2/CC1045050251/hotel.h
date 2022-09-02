#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include <cstring>
using namespace std;


class Hotel{
    public:
        Hotel(string);
        void leeProcesa();
       	void nuevaListaSinDuplicados();
        void seleccionar(int); 
        void estadistico();
		//dia mes y año
        void contar(int, int, int); 
        void eliminarHotel(int); 
    private:
        string nombre;
};