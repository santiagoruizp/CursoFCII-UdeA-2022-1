
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <iomanip>
#include <vector>

class Hotel
{
private:
    std::string nombreArchivo;
    std::vector<std::string> vectorDatos;
    std::vector<std::string> vectorDatosSinDuplicar;

public:
    Hotel();
    ~Hotel();

    void leeProcesa( std::string );
    void nuevaListaSinDuplicados();
    std::vector<std::string> seleccionar( const std::string );
    void estadistico();
    int contar( std::string );
    void eliminarHotel( std::string );
    void seleccionarOpcion();
};
