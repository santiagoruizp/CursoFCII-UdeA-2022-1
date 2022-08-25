
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "CamasHotel.h"


//------------------------------------------------------------------------------------
ProcesoDatos::ProcesoDatos(const string & namefile){

    // Se fija el nombre del archivo
    filename = namefile;

}

//------------------------------------------------------------------------------------
void ProcesoDatos::leeProcesa(){

    // Objeto para lectura de archivos.
    ifstream inFile;
    inFile.open(filename.c_str());

    // Se comprueba que el archivo exista.
    if (inFile.fail()){
        cout << "\nEl archivo llamado " << filename << " no se abrió exitosamente"<< endl;
        exit(0);
    }

    // Se cuenta el número de líneas y se carga en memoria.
    string line;
    inFile >> line;

    while (inFile.good()){
        // Se carga el archivo en un vector
        FILE.push_back(line);
        // Se almacena el número de líneas
        filelines++;
        inFile >> line;
    }
    
    // Se cierra el archivo
    inFile.close();

    // Se imprime el archivo
    ImprimirArchivo(filename);


}

//------------------------------------------------------------------------------------
void ProcesoDatos::nuevaListaSinDuplicados(){

    // Se crea el archivo para almacenar sin repetir
    string sinrep = "NoDuplicado.txt";
    ofstream outFile;
    outFile.open(sinrep.c_str(), std::ofstream::out);

    // Entero para filtrar la repetición
    int sentinel;

    // Se escriben las líneas no repetidas
    for (int i = 0; i <= FILE.size()-1; i++){

        // Se inicializa en 1
        sentinel = 1;

        for (int j = i + 1; j <= FILE.size()-1; j++){

            // Si algún elemento siguiente en el arreglo FILE es igual se cambia sentinel para evitar que se escriba en NoDuplicado.txt
            if (FILE[j] == FILE[i]){
                sentinel = 0;
                break;
            }
        }

        // Si el sentinela no fue cambiado, se escribe en NoDuplicado.txt
        if (sentinel == 1)
            outFile << FILE[i] << "\n";
    }

    // Se libera la memoria 
    FILE.clear();

    // Se cierra el archivo
    outFile.close();

    // Se imprime el archivo
    ImprimirArchivo(sinrep);

    cout<<"Información guardada en archivo NoDuplicado.txt"<<endl;


}

//------------------------------------------------------------------------------------
void ProcesoDatos::seleccionar(string & buscar){

    // Se crea el nombre del archivo a almacenar los datos
    string solicitado = ".txt";
    solicitado.insert (0,buscar);

    // String a buscar en el archivo
    string dotcomma = ";";
    buscar += dotcomma;
    buscar.insert (0,";");

    // Objeto para lectura de archivos.
    string sinrep = "NoDuplicado.txt";
    ifstream inFile;
    inFile.open(sinrep.c_str());

    // Se comprueba que el archivo exista.
    if (inFile.fail()){
        cout << "\nEl archivo llamado " << sinrep << " no se abrió exitosamente"<< endl;
        exit(0);
    }

    // Se crea el archivo para almacenar los datos requeridos
    ofstream outFile;
    outFile.open(solicitado.c_str(), std::ofstream::out);

    // Se buscan y guardan los datos solicitados
    string line;
    inFile >> line;

    while (inFile.good()){

        // Búsqueda de los datos
        int found = line.find(buscar);
        // Escritura de los datos
        if (found != string::npos)
            outFile<< line <<endl;
        inFile >> line;
    }

    // Se cierran los archivos
    inFile.close();
    outFile.close();

    // Se imprime el archivo
    ImprimirArchivo(solicitado);

    cout<<"Información guardada en archivo "<< solicitado <<endl;
}

//------------------------------------------------------------------------------------
void ProcesoDatos::estadistico(){

     // Objeto para lectura de archivos.
    string sinrep = "NoDuplicado.txt";
    ifstream inFile;

    // Se comprueba que el archivo exista.
    if (inFile.fail()){
        cout << "\nEl archivo llamado " << sinrep << " no se abrió exitosamente"<< endl;
        exit(0);
    }

    // Variable para registral las camas
    int reg_cam;

    for (int i = 11; i <= 20; i++){

        reg_cam = 0;

        // String a buscar en el archivo
        string code = to_string(i);
        string dotcomma = ";";
        code += dotcomma;
        code.insert (0,";");

        // Se cargan las líneas del archivo
        inFile.open(sinrep.c_str());
        string line;
        inFile >> line;

        while (inFile.good()){

            // Búsqueda de los datos
            int found = line.find(code);
            // Escritura de los datos
            if (found != string::npos)
                reg_cam++;
            inFile >> line;
        }
        
         // Se cierran los archivos
        inFile.close();

    if (reg_cam > 0)
        cout<<"El hotel " << i << " tiene " << reg_cam << " camas registradas en el archivo."<<endl;
    }
}

//------------------------------------------------------------------------------------
void ProcesoDatos::contar(string & fecha){

    // Variable para almacenar la ocupación
    int ocupacion = 0;

    // Objeto para lectura de archivos.
    string sinrep = "NoDuplicado.txt";
    ifstream inFile;
    inFile.open(sinrep.c_str());

    // Se comprueba que el archivo exista.
    if (inFile.fail()){
        cout << "\nEl archivo llamado " << sinrep << " no se abrió exitosamente"<< endl;
        exit(0);
    }

    // Se buscan los datos solicitados
    string line;
    inFile >> line;

    while (inFile.good()){

        // Búsqueda de los datos
        int found = line.find(fecha);
        // Si se encuentra la fecha se suma 1 a la ocupación
        if (found != string::npos)
            ocupacion++;
        inFile >> line;

    }
    // Se cierra el archivo
    inFile.close();

    // Se imprime la ocupación de tal fecha
    if (ocupacion > 0)
        cout<<"La ocupación en la fecha "<< fecha << " es " << ocupacion <<endl;
    else 
        cout<<"No existen datos de la fecha "<< fecha <<endl;

}

//------------------------------------------------------------------------------------
void ProcesoDatos::eliminarHotel(string & eliminar){


     // Se crea el nombre del archivo a almacenar los datos
    string solicitado = "Eliminado.txt";
    solicitado.insert (0, eliminar);

    // String a buscar en el archivo
    string dotcomma = ";";
    eliminar += dotcomma;
    eliminar.insert (0,";");

    // Objeto para lectura de archivos.
    string sinrep = "NoDuplicado.txt";
    ifstream inFile;
    inFile.open(sinrep.c_str());

    // Se comprueba que el archivo exista.
    if (inFile.fail()){
        cout << "\nEl archivo llamado " << sinrep << " no se abrió exitosamente"<< endl;
        exit(0);
    }

    // Se crea el archivo para almacenar los datos requeridos
    ofstream outFile;
    outFile.open(solicitado.c_str(), std::ofstream::out);

    // Se buscan y guardan los datos solicitados
    string line;
    inFile >> line;

    while (inFile.good()){

        // Búsqueda de los datos
        int found = line.find(eliminar);
        // Escritura de los datos
        if (found != string::npos){
            inFile >> line;
            continue;
        }
        outFile<< line <<endl;
        inFile >> line;
    }

    // Se cierran los archivos
    inFile.close();
    outFile.close();

    // Se imprime el archivo
    ImprimirArchivo(solicitado);

    cout<<"Información guardada en archivo "<< solicitado <<endl;

}

//------------------------------------------------------------------------------------
void ProcesoDatos::ImprimirArchivo(const string & nombre ){

    // Objeto para lectura de archivos.
    ifstream inFile;
    inFile.open(nombre.c_str());

    // Se comprueba que el archivo exista.
    if (inFile.fail()){
        cout << "\nEl archivo llamado " << nombre << " no se abrió exitosamente"<< endl;
        exit(0);
    }

    // Se imprime el archivo.
    string line;
    inFile >> line;

    while (inFile.good()){
        cout << line << endl;
        inFile >> line;
    }
    
    // Se cierra el archivo
    inFile.close();
}