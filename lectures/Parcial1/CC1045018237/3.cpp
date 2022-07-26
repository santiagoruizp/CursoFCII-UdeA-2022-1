#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;



class Complejo 
{
    private: 
        double parteReal;           /*declaramos los valores como de doble presicion*/
        double parteImaginaria;    /* Representamos datos tipo private */
    public:
        Complejo(double = 0.0, double = 0.0);
        void suma(const Complejo &); // función miembro public para la suma
        void resta(const Complejo &); // función miembro public para la resta
        void printComplejo(void);     // función miembro public para la impresión de números complejos
        void setNumeroComplejo(double, double);
}; //fin de declaracion de la clase


Complejo::Complejo(double real, double imaginario ) // constructor, define la función con dos parametros de doble presición
{ setNumeroComplejo(real,imaginario);}

void Complejo::suma(const Complejo &a )  // void, no devuelve ningun valor
{
    parteReal += a.parteReal;   //las parte reales  se suma juntas
    parteImaginaria += a.parteImaginaria; // las partes imaginarias se suman juntas
}

void Complejo::resta(const Complejo &s )
{
    parteReal -=  s.parteReal; // las partes reales se restan juntas 
    parteImaginaria -= s.parteImaginaria; // las partes imaginarias se restan juntas
}

void Complejo::printComplejo(void)  // con esta función mostramos en pantalla la parte real e imaginaria
{ cout << '(' << parteReal << " , " << parteImaginaria << ')'; }

void Complejo::setNumeroComplejo(double rp, double ip) // definimos esta función con paramatros de doble presición
{
    parteReal = rp;          // reasignamos estos nuevos datos miembros
    parteImaginaria = ip;
}



int main()
{
    Complejo b(2.3, 10.5), c(6.3, 19.2); // creamos dos objetos que son dos números complejos
    b.printComplejo(); // imprimimos el número b, el número c y su suma
    cout << " + ";
    c.printComplejo();
    cout << " = ";
    b.suma( c );
    b.printComplejo();


    cout << '\n';
    b.setNumeroComplejo(10, 1); // tenemos un nuevo par de números y los restamos
    c.setNumeroComplejo(11, 5);
    b.printComplejo();
    cout << " - ";
    c.printComplejo();
    cout << " = ";
    b.resta(c);
    b.printComplejo();
    cout << endl;
   // tambien son mostradoe en la forma a-ib
    return 0;


}
 
/* Podriamos programar la multipicacion y división de números complejos, pero de esta manera seria */
/* muy engorroso, pero se podria hacer mas facil si los convertimos a forma polar, es decir, en terminos */
/* de r y tetha. otra oprarción podria ser multiplicar números complejos por una constante , etc.*/ 