#include "hotel.h"
using namespace std;

Turismo::Turismo(string name )
{
nameArchivo = name;
}

void Turismo::imprimir(const vector<string>& vect)
{
  
    int i, n=vect.size();
    for (i=0; i<n; i++)
        cout<<vect[i]<<endl;
    
    return;

}
void Turismo::leeProcesa(ifstream& inFile, string fileName)
{
    vector<string> listado;
    string linea;  
    inFile.open(fileName.c_str());
    /*
    if (inFile.fail()) // verifica si el archivo pudo ser leido
    {
        cout<<"\nEl archivo no pudo ser abierto"
            <<"\nPor favor verifique que el nombre sea correcto"<<endl;
        exit(1);
    }
    */
    while (inFile.good())// guarda la informacion en el vector listaHotel
    {
        listado.push_back(linea);
        inFile>>linea;
    }
    
    inFile.close();
    list= listado;
    return imprimir(list);   
}

vector<string> Turismo::getleeProcesa() const 
{
    return list;
}

void Turismo::nuevaListaSinDuplicados(const vector<string>& v)

{   
    vector<string> new_v;// se define un nuevo vector porque v es const
    new_v=v; // cambia new_v ya que v es const 
    auto end = new_v.end();
    for (auto it = new_v.begin(); it != end; ++it) {
        end = remove(it + 1, end, *it);
    }
 
    new_v.erase(end, new_v.end());
    new_vect= new_v;// se almacena para utilizarlo con get
    return imprimir(new_vect); 
    
}

vector<string> Turismo::getnuevalista()const 
{
    return new_vect;// nueva lista sin duplicados
}


void Turismo::seleccionar(const vector<string>& v) 
{
    string codigo;
    vector<string> seleccion;
    int i, conteo=0;
    cout<<"Ingrese el codigo del hotel a filtrar: ";
    cin>>codigo;
    for(i=1; i<v.size(); i++)// selecciona y guarda en seleccion
    {
        if(v[i].substr(9,2)==codigo)
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
void Turismo::estadistico(const vector<string>& v)
{
  int cont[7]={0};
  //int num[7]={11,14,15,16,17,19,20};
  const char* num[7]={"11","14","15","16","17","19","20"};
  int i;
  int j;
  for(i=1; i<v.size(); i++)
    {for (j=0; j<7;j++)
      if(v[i].substr(9,2)==num[j])
        { 
          cont[j]++;
        }

    }
  for( int n=0; n<7;n++){
     cout<<"Hotel "<<num[n]<< " tiene en total "<<cont[n]<<" cama(s) distintas"<<endl;
  }
};

void Turismo::contar(const vector<string>& v)
{
 string dd,mm,aa, fecha;
 int i, acumulado=0 ;
 cout<<"Ingrese una fecha dd mm aa:";
 cin>>dd>>mm>>aa;

 fecha=aa+mm+dd;
 
 bool existeFecha=true;
 for (int i=1; i<v.size();i++)
 {
    if(v[i].substr(0,8)==fecha){
        
        acumulado++;
    }
    

 }
 if (acumulado==0)
  cout<< "Fecha invalida"<<endl;
 else{
    //cout<<"Fecha"<<fecha;
    cout<<"En la fecha se ocuparon "<<acumulado<<" cama(s)"<<endl;
    
    
 } 
}


/*
void Turismo::eliminarHotel( vector<string>& v)


{

 
string codigo;
cout<<"Ingrese codigo:"<< endl;
cin>> codigo;
vector<string> new_v;
for(int i= 1; i<v.size();i++){
    if(v[i].substr(9,2)!=codigo)
    {
        new_v.push_back(v[i]);

    }
//cout<< codigo<< "Nuevo listado:"<<endl;
imprimir(new_v);
}



}
*/ // No pude definir bien la función y daba error :c



string Turismo::getName()const
{
  return nameArchivo;
}