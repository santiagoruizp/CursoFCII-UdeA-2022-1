//
// Created by kevin on 28/08/22.
//

#include "Hotel.h"

Hotel::Hotel(const string &nombreArchivo) : nombreArchivo(nombreArchivo) {
    leeProcesa();
    nuevaListaSinDuplicados();
}

void Hotel::leeProcesa() {
    ifstream archivoEntrada( Hotel::nombreArchivo);
    if ( archivoEntrada.fail() ){
        cout << "No se pudo abrir el archivo" << endl;
        exit( 1 );
    }
    else{
        string linea;
        vector <string> vector1;
        while (getline(archivoEntrada,linea))
        {
            vector1.push_back(linea);
        }
        Hotel::datosArchivo = vector1;
        archivoEntrada.close();
    }
}

void Hotel::nuevaListaSinDuplicados() {
    //    Eliminar repetidos
    std::sort(Hotel::datosArchivo.begin(), Hotel::datosArchivo.end());
    Hotel::datosArchivo.erase(std::unique(Hotel::datosArchivo.begin(), Hotel::datosArchivo.end()), Hotel::datosArchivo.end());

    //    Convertir vector de strings en un vector de vectores de strings
    basic_string<char> temporal;
    vector<string> info;
    vector<vector<string>> datos1;
    for (string dato: Hotel::datosArchivo) {
        stringstream X(dato);
        while (getline(X, temporal, ';')) {
            info.push_back(temporal);
        }
        datos1.push_back(info);
        info.clear();
    }
    datos1.pop_back();
    Hotel::datos = datos1;
}

vector<vector<string>> Hotel::seleccionar(const string& hotelBuscar) {
    vector<vector<string>> hotel;
    for(vector<string> i: Hotel::datos){
        if(i[1] == hotelBuscar){
            hotel.push_back(i);
        }
    }
    return hotel;
}

void Hotel::estadistico() {
    cout << "\n";
    cout << "Los datos de las habitaciones de cada hotel son:  " << endl;
    vector<string> codigosHoteles;
    for(vector<string> hotel: Hotel::datos){
       codigosHoteles.push_back(hotel[1]);
    }
    std::sort(codigosHoteles.begin(), codigosHoteles.end());
    codigosHoteles.erase(std::unique(codigosHoteles.begin(), codigosHoteles.end()), codigosHoteles.end());
    for(string codigoHotel: codigosHoteles) {
        cout << "El hotel " << codigoHotel << " tiene en total " << seleccionar(codigoHotel).size() << " cama(s) distintas"
             << endl;
    }
    cout << "\n";
}

void Hotel::contar(const string& fechaBuscar) {
    int camasOcupadas = 0;
    for(vector<string> i: Hotel::datos){
        if(i[0] == fechaBuscar){
            camasOcupadas++;
        }
    }
    cout << "\n";
    cout << "La cantidad de camas ocupadas el dia " << fechaBuscar << " es de: " << camasOcupadas << endl;
    cout << "\n";
}

void Hotel::eliminarHotel(const string& hotelEliminar) {
    vector<vector<string>> auxiliar;
    for(vector<string> i: Hotel::datos){
        if(i[1] != hotelEliminar){
            auxiliar.push_back(i);
        }
    }
    Hotel::datos.clear();
    Hotel::datos = auxiliar;
    auxiliar.clear();
    cout << "\n";
    cout << "Los nuevos datos son:  " << endl;
    for(vector<string> i: Hotel::datos){
        cout << i[0] << " " <<  i[1]  <<  " " << i[2]<< endl;
    }
    cout << "\n";
}

void Hotel::imprimirDatosArchivo() {
    for(string i: Hotel::datosArchivo){
        cout << i << endl;
    }
}

void Hotel::imprimirDatosPrograma() {
    for(vector<string> i: Hotel::datos){
        cout << i[0] << " " <<  i[1]  <<  " " << i[2]<< endl;
    }
}




