#ifndef HOTEL
#define HOTEL

#include <string>
#include <vector>

using namespace std;

//Se crea la clase DatosHotel la cual permite realizar todas las funciones requeridas para el hotel

class DatosHotel{
    public:
    //funciones que permite resolver lo que se debe hacer sobre el archivo
        DatosHotel( const string );
        void leeProcesa();
        void nuevaListaSinDuplicados();
        vector <string> seleccionar(const string);// devuelve un vector con las camas del hotel referido
        void estadistico();
        void contar(const string);
        void  eliminarHotel(const string);
        string imprimir(const string);// nos permite imprimir cada fila sin el ; y separada de buena manera

            
        private:
         vector <string> File;// lista con datos sin duplicados
         vector <string> FileCompleto;//lista con datos originales

         string Name;//nombre del archivo de lectura
};


#endif