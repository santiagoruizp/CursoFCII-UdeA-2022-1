/*
Santiago Ruiz Piedrahita
Parcial #1 
Punto #3

El codigo hace aritmetica de numeros complejos
*/
#include <iostream>
#include <string>

using namespace std;

// clase complejos
class Complejos
{
    public:
    Complejos( string ); // el constructor
    string NombreFun(string);
    void MostrarMensaje(); 
    void asignarDatos();
    double obtenerParteReal();
    double obtenerParteImaginaria();
    void Suma();
    void Resta();
    void Multiplicacion();
    void MostrarNumero();
    
    // Se pueden hacer mas operaciones, solo es necesario mirar el resultado general de las mismas
 
    private:
    double ParteReal;
    double ParteImaginaria;
};

// Definicion constructor
Complejos::Complejos(string nombre)
{
  NombreFun(nombre);
}

string Complejos::NombreFun(string nombre)
{
 return nombre;
}

// Mensaje al usuario
void Complejos::MostrarMensaje()
{
    cout << "El programa hace aritmetica de numeros complejos"<< endl;   
}

// Mensaje del numero
void Complejos::MostrarNumero()
{
    if (ParteImaginaria>=0)
        cout <<ParteReal<<"+"<<ParteImaginaria<<"i"<< endl;   
    else
        cout <<ParteReal<<ParteImaginaria<<"i"<< endl;
}

// Asigna los datos que entra el usuario
void Complejos::asignarDatos()
{
    cout << "Ingrese la parte real e imaginaria del numero" << endl;
    cin >> ParteReal >> ParteImaginaria ;
}

// Muestra la parte real
double Complejos::obtenerParteReal()
{
    cout << "La parte real es: "<< ParteReal << endl ;
    return ParteReal;
}

// Muestra la parte imaginaria
double Complejos::obtenerParteImaginaria()
{
    cout << "La parte imaginaria es: "<< ParteImaginaria << endl ;
    return ParteImaginaria;
}

// Suma 2 numeros complejos
void Complejos::Suma()
{
    cout << "Suma de 2 numeros complejos " << endl ;
    cout << "Ingrese el primer numero " << endl ;
    asignarDatos();
    double Re1 = ParteReal;
    double Im1 = ParteImaginaria;
    cout << "Ingrese el segundo numero " << endl ;
    asignarDatos();
    double Re2 = ParteReal;
    double Im2 = ParteImaginaria;
    
    ParteReal = Re1 + Re2;
    ParteImaginaria = Im1 + Im2;
    
    cout<<"("<<Re1<<"+"<<Im1<<"i) + ("<<Re2<<"+"<<Im2<<"i) ="<<endl;
    MostrarNumero();
}

// Resta 2 numeros complejos
void Complejos::Resta()
{
    cout << "Resta de 2 numeros complejos " << endl ;
    cout << "Ingrese el primer numero " << endl ;
    asignarDatos();
    double Re1 = ParteReal;
    double Im1 = ParteImaginaria;
    cout << "Ingrese el segundo numero " << endl ;
    asignarDatos();
    double Re2 = ParteReal;
    double Im2 = ParteImaginaria;
    
    ParteReal = Re1 - Re2;
    ParteImaginaria = Im1 - Im2;
    
    cout<<"("<<Re1<<"+"<<Im1<<"i) - ("<<Re2<<"+"<<Im2<<"i) ="<<endl;
    MostrarNumero();
}

// Multiplica 2 numeros complejos
void Complejos::Multiplicacion()
{
    cout << "Multiplica 2 numeros complejos " << endl ;
    cout << "Ingrese el primer numero " << endl ;
    asignarDatos();
    double Re1 = ParteReal;
    double Im1 = ParteImaginaria;
    cout << "Ingrese el segundo numero " << endl ;
    asignarDatos();
    double Re2 = ParteReal;
    double Im2 = ParteImaginaria;
    
    ParteReal = (Re1 * Re2)+((-1)*(Im1 * Im2));
    ParteImaginaria = (Re1*Im2)+(Re2*Im1);
    
    cout<<"("<<Re1<<"+"<<Im1<<"i) * ("<<Re2<<"+"<<Im2<<"i) ="<<endl;
    MostrarNumero();
}

// Funcion main
int main()
{
    Complejos mi("Mi programa");
    mi.MostrarMensaje();  // mensaje bienvenida
    mi.asignarDatos(); // asigna datos
    mi.obtenerParteReal(); // saca la parte real
    mi.obtenerParteImaginaria(); // saca la parte imaginaria
    mi.MostrarNumero(); // muestra el numero
    mi.Suma(); // suma 2 numeros complejos
    mi.Resta(); // resta 2 numeros complejos
    mi.Multiplicacion(); // Multiplica 2 numeros complejos
    
    return 0;
}
