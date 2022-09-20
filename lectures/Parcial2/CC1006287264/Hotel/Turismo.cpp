#include<iostream>
#include<fstream>
#include<cstdlib> 
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void menu(); // funcion prototipo para mostrar menu 
void imprimir(const vector<string>&); // funcion prototipo para imprimir vector, es usado dentro de algunas de las sig funct
vector<string> leeProcesa(ifstream&, string); // funcion prototipo para leer el archivo, la informacion se almacena en un vector
vector<string> nuevaListaSinDuplicados(const vector<string>&); // funcion prototipo elimina informacion redundante del vector leido
void seleccionar(const vector<string>&); // funcion prototipo filtra la informacion por codigo hotel
void estadistico(const vector<string>&); // funcion prototipo muestra la ocupacion en los distintos hoteles
void contar(const vector<string>&); // funcion prototipo filtra por fecha
void eliminarHotel(vector<string>&); // funcion prototipo elimina por cod, unica funcion con entrada no const, por lo tanto afecta el vec de enrada

int main()
{
    int i;
    ifstream infile; 
    string namefile = "camas_hotel.txt";
    vector<string> muestraListado, sinDuplicados; // 
    enum Continuidad {CONTINUAR,SALIR}; // para efectos de continuidad
    Continuidad estado=CONTINUAR;
    muestraListado=leeProcesa(infile, namefile); // vector que contiene info leida
    sinDuplicados=nuevaListaSinDuplicados(muestraListado); // vector con la info que se manipulara
    menu();

    while (estado==CONTINUAR) // Para mantenerse dentro a menos que se desee salir
    {
        int opcion;
        cin >> opcion;
        if (opcion==1 || opcion==2 || opcion==3 || opcion==4 || opcion==5 || opcion==6)
        {
            switch (opcion)
            {
            case 1:
                imprimir(sinDuplicados); 
                break;
            case 2:
                seleccionar(sinDuplicados);
                break;
            case 3:
                estadistico(sinDuplicados);
                break;
            case 4:
                contar(sinDuplicados);
                break;
            case 5:
                eliminarHotel(sinDuplicados);
                break;
            case 6:
                estado = SALIR;
                break;
            default:
                break;
            }
        }
        else
        {
            cout<<"Opcion no valida"<<endl;
            estado = SALIR;
        }    
    }    
    return 0;
}




void imprimir(const vector<string>& v)
{
    int i, n=v.size();
    for (i=0; i<n; i++)
        cout<<v[i]<<endl;
    
    return;
}
vector<string> leeProcesa(ifstream& inFile, string fileName)
{
    vector<string> listadoHotel;
    string linea;  
    inFile.open(fileName.c_str());

    if (inFile.fail()) // verifica si el archivo pudo ser leido
    {
        cout<<"\nEl archivo no pudo ser abierto"
            <<"\nPor favor verifique que el nombre sea correcto"<<endl;
        exit(1);
    }
    while (inFile.good())// guarda la informacion en el vector listaHotel
    {
        listadoHotel.push_back(linea);
        inFile>>linea;
    }
    inFile.close();
    return listadoHotel;    
}

vector<string> nuevaListaSinDuplicados(const vector<string>& v)
{
    vector<string> new_vec;
    new_vec=v;
    auto end=new_vec.end();
    for (auto i=new_vec.begin(); i != end; ++i)//el ciclo remueve los duplicados
    {
        end=remove(i+1,end,*i);
    }
    new_vec.erase(end, new_vec.end());

    return new_vec;
}

void seleccionar(const vector<string>& v)
{
    string codHotel;
    vector<string> seleccion;
    int i, conteo=0;
    cout<<"Ingrese el codigo del hotel a filtrar: ";
    cin>>codHotel;
    for(i=1; i<v.size(); i++)// selecciona y guarda en seleccion
    {
        if(v[i].substr(9,2)==codHotel)
        {    
            seleccion.push_back(v[i]);
            conteo++;
        }
    }
    if (conteo==0)
        cout<<"\nNo se encontro ningun Hotel con ese codigo"<<endl;
    else
        imprimir(seleccion);

    return;    
}

void estadistico(const vector<string>& v)
{
    int frecuencia_11{0};
    int frecuencia_14{0};
    int frecuencia_15{0};
    int frecuencia_16{0};
    int frecuencia_17{0};
    int frecuencia_19{0};
    int frecuencia_20{0};
    int i;
    for(i=1; i<v.size(); i++)
    {
        if(v[i].substr(9,2)=="11")
            frecuencia_11++;
        if(v[i].substr(9,2)=="14")
            frecuencia_14++;
        if(v[i].substr(9,2)=="15")
            frecuencia_15++;
        if(v[i].substr(9,2)=="16")
            frecuencia_16++;
        if(v[i].substr(9,2)=="17")
            frecuencia_17++;
        if(v[i].substr(9,2)=="19")
            frecuencia_19++;
        if(v[i].substr(9,2)=="20")
            frecuencia_20++;    
    }
    cout<<"Hotel 11 tiene en total "<< frecuencia_11 <<" cama(s) registradas";
    cout<<"\nHotel 14 tiene en total "<< frecuencia_14 <<" cama(s) registradas";
    cout<<"\nHotel 15 tiene en total "<< frecuencia_15 <<" cama(s) registradas";
    cout<<"\nHotel 16 tiene en total "<< frecuencia_16 <<" cama(s) registradas";
    cout<<"\nHotel 17 tiene en total "<< frecuencia_17 <<" cama(s) registradas";
    cout<<"\nHotel 19 tiene en total "<< frecuencia_19 <<" cama(s) registradas";
    cout<<"\nHotel 20 tiene en total "<< frecuencia_20 <<" cama(s) registradas"<<endl;

    return;    
}

void contar(const vector<string>& v)
{
    string dd, mm, aa, fechaIngresada;
    vector<string> ocupacionPorFecha;
    int i, conteo=0;
    cout<<"Ingrese una fecha para verificar su ocupacion, formato de ingreso (dd mm aaaa): ";
    cin>>dd>>mm>>aa;
    fechaIngresada=aa+mm+dd;
    bool existeFecha=true;

    for(i=1; i<v.size(); i++)
    {
        if(v[i].substr(0,8)==fechaIngresada)
        {    
            ocupacionPorFecha.push_back(v[i]);
            conteo++;
        }
    }
    if (conteo==0)
        cout<<"En la fecha referida no hay ocupacion"<<endl;
    else
    {
        cout<<"En la fecha ingresada se ocuparon "<<conteo<<" cama(s)"<<endl;
        cout<<"\nEl listado de ocupacion es:"<<endl;
        imprimir(ocupacionPorFecha);
    }

    return;
}

void eliminarHotel(vector<string>& v)
{
    int i, j, conteo=0;
    string codHotel;
    vector<string> vectorCod;
    cout<<"Ingrese el codigo del hotel que desea eliminar del listado: ";
    cin>>codHotel;

    for(i=1; i<v.size(); i++)
    {
        if(v[i].substr(9,2)==codHotel) // selecciona para luego eliminar
        {    
            vectorCod.push_back(v[i]);
            conteo++;
        }
    }
    if (conteo==0)
        cout<<"\nNo se encontro ningun Hotel con ese codigo"<<endl;
    else
    {   
        for (j=0;j<conteo;j++)// elimina los elementos antes seleccinados
        v.erase(remove(v.begin(), v.end(), vectorCod[j]), v.end());
        imprimir(v);
    }
    return;   
}

void menu()
{
    cout<<"\nBienvenido"<<endl;
    cout<<"\nMenu: "<<endl;
    cout<<" 1. Ver listado"<<endl;
    cout<<" 2. Filtrar por Codigo de Hotel"<<endl;
    cout<<" 3. Ver Estadisticas de Ocupacion"<<endl;
    cout<<" 4. Filtrar por Fecha"<<endl;
    cout<<" 5. Eliminar Registro por Codigo de Hotel"<<endl;
    cout<<" 6. Salir"<<endl;
    cout<<"\nSeleccione una opcion: "<<endl;
}
