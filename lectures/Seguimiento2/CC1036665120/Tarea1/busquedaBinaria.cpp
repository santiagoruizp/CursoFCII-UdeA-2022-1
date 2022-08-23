/*
Tarea1.
La búsqueda binaria es un algoritmo eficiente para encontrar un elemento en una 
lista ordenada de elementos.
Funciona al dividir repetidamente a la mitad la porción de la lista que podría contener al elemento,
hasta reducir las ubicaciones posibles a solo una.
Para terminar, el algoritmo encuentra un elemento que coincide con la clave de búsqueda o 
reduce el subvector hasta un tamaño de cero.
Por favor, Cree un programa en c++ para implementar la búsqueda binaria.
*/

#include <iostream>
#include <vector>

using namespace std;

// ------------------------------
// INGRESA EL VALOR A BUSCAR 
// ------------------------------
int ingresarValor(){
    
    int valorBuscar;
    cout << "Ingresa el valor a buscar: ";
    cin >> valorBuscar;

    while (cin.fail() || valorBuscar > 50)
    {
        if (cin.fail())
        {
            cout << "Debes ingresar un número." << endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
        if (valorBuscar > 50)
        {
            cout << "Debes ingresar un número menor o igual a 50" << endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
        
        cin >> valorBuscar;
    }

    return valorBuscar;
}


// ------------------------------
// IMPRIMIR RESULTADO
// ------------------------------
void imprimirResultado(int &posicion, int &val, string tipo){

    if (posicion==-1){
        cout << "No se encontró el valor" <<endl;
    }else{
        cout << "El valor " << val <<  " está en la posición " << posicion << " del " << tipo << endl;
    }
}


// ------------------------------
// BÚSQUEDA EN UN VECTOR
// ------------------------------
int buscarPorVector(int t, vector< int > &vect){

    // posiciones inicial y final
    int l = 0;
    int r = vect.size();

    // valor medio
    int m = static_cast<int>((l+r)/2);

    // mientras el valor en la posición m, no sea el valor a buscar (t)
    while(vect.at(m)!=t){

        // si los valores l y r se cruzan, significa que el valor a buscar no está
        if (l > r){
            return -1;
        }else{
            if (vect.at(m) < t){
                // si el valor en la posición m es menor que el valor a buscar
                // se incrementa una posición
                l = m+1;
                m++;
            }else{
                if (vect.at(m) > t){
                    // si el valor en la posición m es mayor que el valor a buscar
                    // se reduce una posición
                        r = m-1;
                        m--;
                    }
                }
            }
    }

    return m;
}



// ------------------------------
// BÚSQUEDA EN UN ARREGLO
// ------------------------------
int buscarPorArreglo(int t, int *vectPtr, int size){

    // posiciones inicial y final
    int l = 0;
    int r = size / sizeof(int);

    // valor medio
    int m = static_cast<int>((l+r)/2);

    // referencia a la mitad del arreglo
    vectPtr += m;  

    // mientras el apuntador al valor no sea el valor a buscar:
    while (*vectPtr != t)
    {
        if (l>r){
            return -1;
        }else{
            if (*vectPtr<t){
                // si el valor en la posición m es menor que el valor a buscar
                // se incrementa una posición
                l = m+1;
                m++;
                vectPtr++;
            }else{
                if (*vectPtr>t){
                    // si el valor en la posición m es mayor que el valor a buscar
                    // se reduce una posición
                        r = m-1;
                        m--;
                        vectPtr--;
                    }
                }
            }
    }
    return m;
}



// ------------------------------
// MAIN
// ------------------------------
int main()
{
    // ---- BUSCAR POR ARREGLO --- 
    int arrayOrdenado[] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    int valorBuscar = ingresarValor();

    int *arrayOrdenadoPtr = arrayOrdenado;

    int posicion1 = buscarPorArreglo(valorBuscar, arrayOrdenadoPtr, sizeof(arrayOrdenado));

    imprimirResultado(posicion1, valorBuscar, "array");


    // ---- BUSCAR POR VECTOR --- 
    vector<int> vectorOrdenado(begin(arrayOrdenado), end(arrayOrdenado));

    int posicion2 = buscarPorVector(valorBuscar , vectorOrdenado);

    imprimirResultado(posicion2, valorBuscar, "vector");

    return 0;
}
