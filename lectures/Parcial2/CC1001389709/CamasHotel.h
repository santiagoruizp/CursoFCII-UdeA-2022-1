
#ifndef DATA_H
#define DATA_H

#include<vector>
#include <string> 
using namespace std;


class ProcesoDatos{

    public:
        ProcesoDatos(const string &);
        void leeProcesa();
        void nuevaListaSinDuplicados();
        void seleccionar(string &);
        void estadistico();
        void contar();
        void eliminarHotel(string &);

    private:
        string filename;
        int filelines = 0;
        vector<string> FILE = {};
        void ImprimirArchivo(const string &);

};




#endif