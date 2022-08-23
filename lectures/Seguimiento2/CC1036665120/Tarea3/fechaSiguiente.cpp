#include "fechaSiguiente.h"

fechaSiguiente::fechaSiguiente(const int & dia, const int & mes, const int & anio) : fecha( dia, mes, anio )
{
    setAnio( anio );
    setMes( mes );
    setDia( dia );

    fecha::imprimir();
    
}

fechaSiguiente::~fechaSiguiente()
{
}


void fechaSiguiente::setDia( const int dia )
{
    this->diaS = fecha::comprobarDia(dia);
    
}

void fechaSiguiente::setMes( const int mes )
{
    this->mesS = fecha::comprobarMes(mes);
}

void fechaSiguiente::setAnio( const int anio )
{
    this->anioS = fecha::comprobarAnio(anio);
    
}

// ---------------------------------------
// --------- CALCULAR DÍA SIGUIENTE ------
// ---------------------------------------
void fechaSiguiente::diaSig()
{

    static const int diasPorMes[ 13 ] =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Si es el último día del mes
    if ( (fecha::getDia() == diasPorMes[fecha::getMes()] ) || fecha::validarFeb29( fecha::getDia() ) )
    {
        // Si es 28 de febrero y se valida que existe el 29 por ser año bisiesto 
        if ( (fecha::getDia() == 28) && (validarFeb29( fecha::getDia() + 1 )))
        {
            diaS = 29;
            mesS = 2;

        } else {

            // Vuelve a ser el día 1 del mes siguiente
            diaS = 1;
            mesS += 1;
        }

        // Si mes llegó a 13, lo establece en 1 y suma uno al año
        if ( mesS >= 13 ) 
        {
            mesS = 1;  
            anioS += 1;
        }
        
    }else{

        diaS += 1;
    }


    std::cout << "El día siguiente : ";
   

}


// ---------------------------------------
// --------------- IMPRIMIR  -------------
// ---------------------------------------
void fechaSiguiente::imprimir() const
{
    std::cout << diaS << "-" << mesS << "-" << anioS << std::endl;
}