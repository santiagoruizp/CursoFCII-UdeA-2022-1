#include "Hotel.h"

Hotel::Hotel()
{
    this->nombreArchivo = "../camas_hotel.txt";
    
}

Hotel::~Hotel()
{
}


// ------------------------------------------
// ------ LEER Y PROCESAR ARCHIVO -----------
// ------------------------------------------
void Hotel::leeProcesa(std::string nombreArchivo)
{
    std::ifstream archivo( nombreArchivo, std::ios::in );
    std::string linea;

    if ( !archivo )
    {
      std::cout << "No se pudo abrir el archivo" << std::endl;
      exit( 1 );

    } else {
        while ( getline(archivo,linea) )
        {
            // Ingresa cada línea del archivo en un vector 
            this->vectorDatos.push_back(linea);
        }
    }

}



// ------------------------------------------
// ------------ SIN DUPLICADOS ---------------
// ------------------------------------------
void Hotel::nuevaListaSinDuplicados()
{
    int size_1 = this->vectorDatos.size();

    // Primer elemento 
    //this->vectorDatosSinDuplicar.push_back(this->vectorDatos.at(0));
    this->vectorDatosSinDuplicar.push_back(this->vectorDatos.at(1));

    for (size_t i = 2; i < size_1 ; i++)
    {
        bool insert = true;

        // Recorre el vector nuevo. Crece el tamaño del vector de forma dinámica
        for (size_t j = 0; j < this->vectorDatosSinDuplicar.size(); j++)
        {
            // Si el dato del vector original (vectorDatos) en la posición "i" es igual que 
            // algún dato ya ingresado en vectorDatosSinDuplicar,
            // el flag para insertar se pone en false
            if (this->vectorDatos.at(i) == this->vectorDatosSinDuplicar.at(j))
            {
                insert = false;
                
            }
            
        }

        // Si el flag de insertar esta en true, significa que el dato "i" 
        // aún no existe en vectorDatosSinDuplicar 
        if (insert)
        {
            this->vectorDatosSinDuplicar.push_back(this->vectorDatos.at(i));
        }
           
    }
    
    
}



// ------------------------------------------
// ------------ SELECCIONAR HOTEL ------------
// ------------------------------------------
std::vector<std::string> Hotel::seleccionar(const std::string codigo)
{
    std::vector<std::string> hotelSelect;

    int posicion;
    std::string str;
    char *ptr;

    for (size_t i = 0; i < this->vectorDatosSinDuplicar.size(); i++)
    {
        // Convertir string a char
        str = vectorDatosSinDuplicar.at(i);
        char arr[str.length() + 1]; 
        strcpy(arr, str.c_str()); 

        // Split en ;
        ptr = strtok(arr, ";"); 

        // Segunda posición (código del hotel)
        ptr = strtok(NULL,";");

        // Si el codigo del hotel en vectorDatosSinDuplicar 
        // es igual al código ingresado
        if (ptr == codigo)
        {
            hotelSelect.push_back(str);
        }

    }

    return hotelSelect;

    
}


// ------------------------------------------
// ------------ ESTADÍSTICAS ----------------
// ------------------------------------------
void Hotel::estadistico()
{

    const std::string hoteles[] = { "11", "12",  "13",  "14", "15", "16",  "17",  "18",  "19", "20"};

    int size = sizeof(hoteles) / sizeof(std::string);


    for (size_t i = 0; i < size; i++)
    {
        std::vector<std::string> hotel = this->seleccionar(hoteles[i]);
        std::cout << "Hotel " << hoteles[i] << " tiene en total " << hotel.size() << " camas distintas" << std::endl;
    }


}


// ------------------------------------------
// --------------- CONTAR  -------------------
// ------------------------------------------

int Hotel::contar(std::string fecha)
{

    int posicion;
    std::string str;
    char *ptr;
    int contador = 0; 


    for (size_t i = 0; i < this->vectorDatosSinDuplicar.size(); i++)
    {
        // Convertir string a char
        str = vectorDatosSinDuplicar.at(i);
        char arr[str.length() + 1]; 
        strcpy(arr, str.c_str()); 

        // Split en ;
        ptr = strtok(arr, ";"); 

        if (ptr == fecha)
        {
            contador++;
        }
        
    }

    return contador;

}


// ------------------------------------------
// --------------- ELIMINAR HOTEL  ----------
// ------------------------------------------

void Hotel::eliminarHotel(std::string codigo)
{

    //Seleccionar el hotel a eliminar
    std::vector<std::string> hotelEliminar = this->seleccionar(codigo);
    
    // Iterador que apunta al primer elemento de vectorDatosSinDuplicar
    std::vector<std::string>::iterator it = this->vectorDatosSinDuplicar.begin();
    std::vector<std::string> noEliminados;

    // itera a través del vector
    while ( it != this->vectorDatosSinDuplicar.end() )
    {
        bool eliminar = false;
        for (size_t j = 0; j < hotelEliminar.size(); j++)
        {
            // Si el iterador es igual al elemento j de la lista
            if (*it == hotelEliminar.at(j))
            {
                eliminar = true;
            }

        }

        // Si no serán eliminados, agregar a "noEliminados"
        if (!eliminar)
        {
            noEliminados.push_back(*it);
        }

        eliminar = false;

        ++it; 
    } 

    this->vectorDatosSinDuplicar = noEliminados;

    // No eliminados
    for (size_t i = 0; i < this->vectorDatosSinDuplicar.size(); i++)
    {
        std::cout << this->vectorDatosSinDuplicar.at(i) << std::endl;
    }

}



// ------------------------------------------
// ------------- SELECCIONAR FUNCION  ----------
// ------------------------------------------

void Hotel::seleccionarOpcion()
{
    int opcion;
    std::string codigo;
    std::string fecha;
    std::vector<std::string> hotel;
    int camas;

    std::cout << "Elija el número de la fucnión que quiera llamar: " 
    << "\n1. Leer y procesar datos."
    << "\n2. Quitar datos duplicados."
    << "\n3. Seleccionar Hotel"
    << "\n4. Estadísticas" 
    << "\n5. Camas ocupadas por fecha" 
    << "\n6. Eliminar Hotel" << std::endl;

    



    while (true)
    {

        std::cin >> opcion;

        while (std::cin.fail() || (opcion > 7 || opcion < 0))
        {
            if (std::cin.fail())
            {
                std::cout << "Debes ingresar un número." << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
            }
            if (opcion > 7 || opcion < 0)
            {
                std::cout << "Debes ingresar uno de los números de la lista." << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
            }
            
            std::cin >> opcion;
        }
           switch (opcion)
            {
            case 1:
                std::cout << "Ingrese el nombre del archivo: " << std::endl;
                std::cin >> this->nombreArchivo;
                this->leeProcesa(nombreArchivo);
                break;

            case 2:
                std::cout << "Se quitaron los datos duplicados " << std::endl;
                this->nuevaListaSinDuplicados();
                break;

            case 3:
                std::cout << " ---- HOTEL SELECCIONADO ---- " << std::endl;
                std::cout << "Seleciona un Hotel para verlo: " << std::endl;
                std::cin >> codigo;
                hotel = this->seleccionar(codigo);
                for (size_t i = 0; i < hotel.size(); i++)
                {
                    std::cout << hotel.at(i) << std::endl;
                }
                break;

            case 4:
                std::cout << " ---- ESTADISTICAS ---- " << std::endl;
                this->estadistico();
                break;

            case 5:
                std::cout << " ---- CAMAS OCUPADAS EN FECHA ---- " << std::endl;
                std::cout << "Ingresa una fecha (formato aaaammdd) para ver camas ocupadas ese día: " << std::endl;
                std::cin >> fecha;
                camas =this->contar(fecha);
                std::cout << camas << std::endl;
                break;

            case 6:
                std::cout << " ---- ELIMINAR ---- " << std::endl;
                std::cout << "Ingresa el código de un hotel para eliminarlo: " << std::endl;
                std::cin >> codigo;
                this->eliminarHotel(codigo);
                break;
            
            default:
                break;
            }
        

    }
    



}