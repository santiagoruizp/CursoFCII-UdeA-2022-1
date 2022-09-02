
#include <iostream>
using namespace std;
class Cama // creamos una clase cama
{
public:
    string fecha;   // definimos variables y su tipos
    int codigoHospital;
    string numeroCama;
    int dia, mes, anho;

    Cama(string fecha, string codigoHospital, string numeroCama) // constructor función cama
    {   //accedemos mediante punteros
        this->fecha = fecha;
        this->codigoHospital = stoi(codigoHospital);
        this->numeroCama = numeroCama;
        // Extraer la fecha desde el constructor
        this->anho = stoi(fecha.substr(0, 4));
        this->mes = stoi(fecha.substr(4, 2));
        this->dia = stoi(fecha.substr(6, 2));
    }

    void imprimir() // creamos la funcion imprimir
    {
        cout << "Fecha: " << this->fecha << ". Codigo hospital: " << this->codigoHospital << ". Numero cama: " << this->numeroCama << endl;
    }

    bool equivale(Cama *otraCama)
    {
        if (otraCama == NULL)
        {
            return false;
        }
        return this->fecha == otraCama->fecha && this->codigoHospital == otraCama->codigoHospital && this->numeroCama == otraCama->numeroCama;
    }
};


class Nodo  // creamos la clase Nodo
{
public:
    Cama *cama;  // creamos espacios de memoria
    Nodo *siguiente;
    Nodo(Cama *cama)  // constrauctor 
    {
        this->cama = cama;           // cama apunta a cama
        this->siguiente = NULL;  // siguiente no apunta nada
    }
};

class Lista // creamos la clase lista
{

private:
    void agregarRecursivo(Nodo *n, Cama *dato) // agregamos la funcion recursivo rivada
    {
        if (n->siguiente == NULL)
        {
            n->siguiente = new Nodo(dato);
        }
        else
        {
            this->agregarRecursivo(n->siguiente, dato);
        }
    }

    void imprimirRecursivo(Nodo *n) // función imprimir recursivo
    {
        if (n != NULL)
        {
            n->cama->imprimir();
            this->imprimirRecursivo(n->siguiente);
        }
    }
    void eliminarRecursivo(Nodo *n, int codigoHospital) // funcion eliminar recursivo. para el codigo de hospital
    {
        if (n == NULL)
        {
            return;
        }
        if (n->cama->codigoHospital == codigoHospital && n == this->cabeza)
        {
            Nodo *temporal = this->cabeza;
            if (this->cabeza->siguiente != NULL)
            {
                this->cabeza = this->cabeza->siguiente;
                delete temporal;
            }
            else
            {
                this->cabeza = NULL;
            }
            return;
        }
        if (n->siguiente != NULL && n->siguiente->cama->codigoHospital == codigoHospital)
        {
            Nodo *temporal = n->siguiente;
            if (n->siguiente != NULL)
            {
                n->siguiente = n->siguiente->siguiente;
            }
            delete temporal;
        }
        else
        {
            this->eliminarRecursivo(n->siguiente, codigoHospital);
        }
    }

    void eliminarRecursivo(Nodo *n, Cama *camaParaEliminar) // funcion eliminar recursivo
    {
        if (n == NULL)
        {
            return;
        }
        if (n->cama->equivale(camaParaEliminar) && n == this->cabeza)
        {
            Nodo *temporal = this->cabeza;
            if (this->cabeza->siguiente != NULL)
            {
                this->cabeza = this->cabeza->siguiente;
                delete temporal;
            }
            else
            {
                this->cabeza = NULL;
            }
            return;
        }
        if (n->siguiente != NULL && n->siguiente->cama->equivale(camaParaEliminar))
        {
            Nodo *temporal = n->siguiente;
            if (n->siguiente != NULL)
            {
                n->siguiente = n->siguiente->siguiente;
            }
            delete temporal;
        }
        else
        {
            this->eliminarRecursivo(n->siguiente, camaParaEliminar);
        }
    }
    bool existeRecursivo(Nodo *n, Cama *camaBuscada) // funcion existe recursivo cama
    {
        if (n == NULL)
        {
            return false;
        }
        if (n->cama->equivale(camaBuscada))
        {
            return true;
        }
        return this->existeRecursivo(n->siguiente, camaBuscada);
    }
    bool existeRecursivo(Nodo *n, int codigoHospital) // funcion existerecursivo para hospital
    {
        if (n == NULL)
        {
            return false;
        }
        if (n->cama->codigoHospital == codigoHospital)
        {
            return true;
        }
        return this->existeRecursivo(n->siguiente, codigoHospital);
    }

public: // funciones publicas
    Nodo *cabeza;
    void copiaSinDuplicados(Lista *l) // creamos la funcion copia sin duplicado
    {
        Nodo *temporal = this->cabeza;
        while (temporal != NULL)
        {
            if (!l->existe(temporal->cama))
            {
                l->agregar(temporal->cama);
            }
            temporal = temporal->siguiente;
        }
    }
    void eliminar(Cama *cama) // funcion para eliminar la cama
    {
        this->eliminarRecursivo(this->cabeza, cama);
    }
    void eliminar(int codigoHospital) // funcion eliminar por el codigo del hospital
    {
        this->eliminarRecursivo(this->cabeza, codigoHospital);
    }
    void agregar(Cama *cama) // funcion para agregar la cama
    {
        if (this->cabeza == NULL)
        {
            this->cabeza = new Nodo(cama);
        }
        else
        {
            this->agregarRecursivo(this->cabeza, cama);
        }
    }

    void imprimir() // funcion para imprimir
    {
        std::cout << "Imprimiendo lista..." << std::endl;
        this->imprimirRecursivo(this->cabeza);
    }
    bool existe(Cama *camaBuscada) // funcion si exite la cama buscada
    {
        return this->existeRecursivo(this->cabeza, camaBuscada);
    }

    bool existe(int codigoHospital) // funcion si exite por codigo de hospital
    {
        return this->existeRecursivo(this->cabeza, codigoHospital);
    }
};