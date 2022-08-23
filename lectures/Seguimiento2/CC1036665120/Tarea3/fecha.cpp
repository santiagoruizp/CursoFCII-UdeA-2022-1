#include "fecha.h"


fecha::fecha( int dd, int mm, int aa ) 
{
    setAnio( aa );
    setMes( mm );
    setDia( dd );
    
    
    
}

fecha::~fecha()
{
    
}

// ---------------------------------------
// --------------- SET  -------------
// ---------------------------------------

void fecha::setDia( int &dd )
{
    this->dia = comprobarDia( dd );
}


void fecha::setMes( int &mm )
{
    this->mes = comprobarMes( mm );
}

void fecha::setAnio( int &aa )
{
    this->anio = comprobarAnio( aa );
}


// ---------------------------------------
// --------------- GET  -------------
// ---------------------------------------

int fecha::getDia() const {
    return this->dia;
}

int fecha::getMes() const {
    return this->mes;
}

int fecha::getAnio() const {
    return this->anio;
}


// ---------------------------------------
// VALIDAR SI EL 29 DE FEBRERO DEBE EXISTIR 
// ---------------------------------------
bool fecha::validarFeb29( int dd ) const
{

    if ( (mes == 2) && (dd == 29) && ( anio % 400 == 0 ||
					( anio % 4 == 0 && anio % 100 != 0 ) ) )
    {
        return true;
    } 

    return false;

}


// ---------------------------------------
// --- COMPROBAR INFORMACIÓN INGRESADA ---
// ---------------------------------------
int fecha::comprobarDia( int dd ) const
{

    static const int diasPorMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Si es positiva o es menor de los días que tiene el mes
    if ( (dd > 0) && (dd <= diasPorMes[mes]) )
    {   
        return dd; 
    }

    // Si es 29 de febrero de un año bisiestro
    if ( validarFeb29( dd ) )
    {
        return dd;
    }

    std::cout << "Dia invalido (" << dd << ") se establecio en 1."<< std::endl;
    return 1;
    
}


int fecha::comprobarMes( int mm ) const
{

    if ( (mm >= 1)  && (mm <= 12))
    {
        return mm; 
    }

    std::cout << "Mes invalido (" << mm << ") se establecio en 1."<< std::endl;
    return 1;

}


int fecha::comprobarAnio( int aa ) const
{

    if ((aa > 0))
    {   
        return aa;
        
    }

    std::cout << "Año invalido (" << aa << ") se establecio en " << -1*aa << std::endl;;
    return -1*aa;
}


// ---------------------------------------
// --------------- IMPRIMIR  -------------
// ---------------------------------------
void fecha::imprimir() const
{
    std::cout << dia << "-" << mes << "-" << anio << std::endl;
}





