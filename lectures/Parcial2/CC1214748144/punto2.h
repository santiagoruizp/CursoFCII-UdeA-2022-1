#ifndef HOTEL_H
#define HOTEL_H
#include <string>
using namespace std;

class Hotel{
    public:
        Hotel(string);
        void leeProcesa();
       	void nuevaListaSinDuplicados();
        void seleccionar(int); //el parámetro es el código del hotel.
        void estadistico();
        void contar(int, int, int); //dia, mes, año
        void eliminarHotel(int); //codigo del hotel
        private:
         string nombre;
};
#endif 
