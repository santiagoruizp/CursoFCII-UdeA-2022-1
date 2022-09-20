#include <iostream>
#include <sstream>
#include <fstream> // contiene tipos de procesamiento de flujos de archivos
#include <vector>
#include <algorithm>

#include "lista.cpp"

using namespace std;

void leeProcesa(string nombreArchivo, Lista *lista) // inicia el programa e invocamos la función leeProcesa
{ //  leemos el contenido del archivo y almacenará su contenido completo en la memoria
    ifstream archivo(nombreArchivo); // clase orientada ala lectura del archivo
    string linea; // linea será un string
    char delimitador = ';';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {
        stringstream stream(linea); // Convertir la cadena a un stream
        string fecha, codigoHospital, numeroCama;
        // Extraer todos los valores de esa fila
        getline(stream, fecha, delimitador);
        getline(stream, codigoHospital, delimitador);
        getline(stream, numeroCama, delimitador);
        lista->agregar(new Cama(fecha, codigoHospital, numeroCama));
    }
    archivo.close();
}

void nuevaListaSinDuplicados(Lista *original, Lista *sinDuplicados) // función nuevaListaSinDuplicados
{
    original->copiaSinDuplicados(sinDuplicados); // genera una nueva lista sin repetidos
}

void seleccionar(Lista *lista, int codigoHospital, Lista *destino) // función seleccionar
{
    Nodo *temporal = lista->cabeza;
    while (temporal != NULL)
    {
        if (temporal->cama->codigoHospital == codigoHospital)
        {
            destino->agregar(temporal->cama);
        }
        temporal = temporal->siguiente;
    }
}

void estadistico(Lista *lista) // provee la funcionalidad estadistico
{
    // Primero vamos a extraer códigos únicos para los hospitales, ya que no sabemos
    // si van en orden, si son consecutivos y tampoco sabemos los límites
    std::vector<int> codigos;
    Nodo *temporal = lista->cabeza;
    while (temporal != NULL)
    {
        int codigoHospital = temporal->cama->codigoHospital;
        bool existe = find(codigos.begin(), codigos.end(), codigoHospital) != codigos.end();
        if (!existe)
        {
            codigos.push_back(codigoHospital);
        }
        temporal = temporal->siguiente;
    }
    // Ahora recorremos el vector y generamos estadísticas

    for (std::size_t i = 0; i < codigos.size(); i++)
    {
        int codigo = codigos[i];
        int conteo = 0;
        // Recorremos la lista de nuevo por cada código encontrado
        Nodo *temporal = lista->cabeza;
        while (temporal != NULL)
        {
            int codigoHospital = temporal->cama->codigoHospital;
            if (codigoHospital == codigo)
            {
                conteo++;
            }
            temporal = temporal->siguiente;
        }
        cout << "Hospital " << codigo << " tiene en total " << conteo << " cama(s) distintas" << endl;
    }
}

int contar(Lista *lista, int anho, int mes, int dia) // provee la información de contar
{
    Nodo *temporal = lista->cabeza;
    int conteo = 0;
    while (temporal != NULL)
    {
        if (temporal->cama->anho == anho && temporal->cama->mes == mes && temporal->cama->dia == dia)
        {
            conteo++;
        }
        temporal = temporal->siguiente;
    }
    return conteo;
}
void eliminarHospital(Lista *lista, int codigoHospital) // provee la funcionalidad eliminar el hotel. eliminando las ocurrencias
{
    while (lista->existe(codigoHospital))
    {
        lista->eliminar(codigoHospital);
    }
}

void menu() // creamos una función como menu de interacción
{
    string seleccion = ""; // seleccion será un string
    Lista *listaConPosiblesRepetidos = new Lista(); // creamos lista que actualiza
    Lista *listaSinRepetidos = new Lista(); // creamos una lista que actualiza para sin repetidos
    while (seleccion != "g") // entramos en un ciclo hasta que no se marque g como salida
    {
        cout << "a. Crear lista desde archivo " << endl;
        cout << "b. Crear lista sin duplicados" << endl;
        cout << "c. Crear lista de un hospital" << endl;
        cout << "d. Mostrar estadisticas de numero de camas por hospital" << endl;
        cout << "e. Cantidad de camas ocupadas por fecha especificada" << endl;
        cout << "f. Eliminar registro de camas de un hospital" << endl;
        cout << "g. Salir" << endl;
        cout << "Seleccione: " << endl;
        cin >> seleccion;
        if (seleccion == "a") // si se escoge la opción a
        {
            leeProcesa("camas_hotel.txt", listaConPosiblesRepetidos); // lee procesa abre el archivo
            cout << "Lista leida desde archivo: " << endl; // para crear a una lista desde el archivo con psibles repetidos
            listaConPosiblesRepetidos->imprimir(); //  luego se imprime
        }
        if (seleccion == "b") // si se escoge la opcion b
        {
            nuevaListaSinDuplicados(listaConPosiblesRepetidos, listaSinRepetidos);  // creamos una lista sin duplicados
            cout << "Lista sin duplicados: " << endl; // titulo
            listaSinRepetidos->imprimir(); // muetra la lista sin duplicados
        }
        if (seleccion == "c") // si se escoge la opción c. crea la lista de un hospital
        {
            int codigo;
            cout << "Ingresa el codigo de hospital: " << endl; // pedimos el codigo del hospital
            cin >> codigo; // se introduce el codigo del hospital
            Lista *deHospital = new Lista();
            seleccionar(listaSinRepetidos, codigo, deHospital);
            cout << "Datos del hospital solicitado: " << endl;
            deHospital->imprimir(); // imprimimos la lista del hospital
        }
        if (seleccion == "d") // muestra la estadistica del numero de camas del hospital
        {
            cout << "Estadisticas de la lista:" << endl;
            estadistico(listaSinRepetidos);
        }
        if (seleccion == "e") // muestra las fechas ocupadas, pero se necesitan datos especificos como:
        {
            int anho, mes, dia;  // dia,mes, año
            cout << "Ingresa el anho: " << endl;
            cin >> anho;
            cout << "Ingresa el mes: " << endl;
            cin >> mes;
            cout << "Ingresa el dia: " << endl;
            cin >> dia;
            int conteo = contar(listaSinRepetidos, anho, mes, dia);
            cout << "Camas ocupadas en fecha: " << conteo << endl; // muestra las camas ocupadas
        }
        if (seleccion == "f") // elimina el registro de la cama del hospital, se necesita el codigo
        {
            int codigo;
            cout << "Ingresa el codigo de hospital para eliminar: " << endl;
            cin >> codigo;
            eliminarHospital(listaSinRepetidos, codigo);
            cout << "Lista despues de haber eliminado el hospital: " << endl;
            listaSinRepetidos->imprimir();
        }
    }
}

int main()
{
    menu(); // llamamos al menu desde el maina
    return 0;
}