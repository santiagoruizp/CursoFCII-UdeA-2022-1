//
// Created by kevin on 28/08/22.
//

#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Hotel {
public:
    explicit Hotel(const string &nombreArchivo);
    void leeProcesa();
    void nuevaListaSinDuplicados();
    vector<vector<string>> seleccionar(const string&);
    void estadistico();
    void contar(const string&);
    void  eliminarHotel(const string&);
    void imprimirDatosArchivo();
    void imprimirDatosPrograma();

private:
    string nombreArchivo;
//    Datos originales del archivo
    vector<string> datosArchivo;
//    Datos con los que se trabajara
    vector<vector<string>> datos;
};


#endif //HOTEL_HOTEL_H
