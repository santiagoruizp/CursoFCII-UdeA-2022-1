
#include "turismo.h"
using namespace std;

Turismo::Turismo( string name )
{
nameArchivo = name;
}

void Turismo::imprimir(const int nA[] ,const int nM[],const int nD[],const int nH[],const int nC[],int t) const
{
  cout << left << setw( 15 ) << "date"<< setw( 15 ) << "Hotel_code"<< setw( 15 ) << "numero_de_habitacion" << endl;
  
  for (int i=1; i< t  ; i++){
  cout << nA[i]<<'/'<<nM[i]<<'/'<< setw(8)<<nD[i] <<setw(15)<< nH[i]<< nC[i] << endl;
  }
}

void Turismo::leeProcesa(string name)
{
  int cont = 0;
  string ID, fname, lname;
  string course;
  ifstream inFile(name);
  if (inFile.is_open()){
    string line;
    while( getline(inFile,line) ){
      stringstream ss(line);
      getline(ss,ID,';');    
      cout<<left<<setw(15)<<ID;
      getline(ss,fname,';'); 
      cout<<left<<setw(15)<<fname;
      getline(ss,lname,';'); 
      cout<<left<<setw(15)<<lname;
      
      int num, num2,num3;
      stringstream s1;
      stringstream s2;
      stringstream s3;
      s1 << fname;
      s1 >> num;
      s2 << lname;
      s2 >> num2;
      s3 << ID;
      s3 >> num3;
      fecha[cont] = num3;
      hotel[cont] = num;
      cama[cont] = num2;
      cont += 1;
      vector<string> enrolled;
      while( getline(ss,course,';') ){
        enrolled.push_back(course); cout<<course;
        }
        cout<<"\n";
      }
    }
    // dividimos la fecha en su formato
    for (int i=1 ; i<18 ; i++){
      año[i] = (fecha[i]/10000) ;
      mes[i] = (fecha[i]%1000)/100 ; 
      dia[i] = (fecha[i]%10)/1 ; 
      }
    cout<<"\n";
    cout<<"Mejorando la presentacion de los datos"<<endl;
    imprimir(año,mes,dia,hotel,cama,18);
}

void Turismo::nuevaListaSinDuplicados()
{
  int cont[19]={0};
  for (int i=0; i<18 ; i++){
    for (int j=1+i; j<20 ; j++){ 
      if (fecha[i]==fecha[j] && hotel[i]==hotel[j] && cama[i]==cama[j]){
      cont[j]=j; // saco el indice de los repetidos
      } 
    }     
  }
  
  int co=0;
  for (int k=1; k<18;k++){
    if (cont[k]==0){
    co +=1;
    año[co] = año[k];
    mes[co] = mes[k];
    dia[co] = dia[k];
    hotel[co] = hotel[k];
    cama[co] = cama[k];
    }
  }
  // como se  reemplaza en el mismo arreglo, cambiemos los ultimos por 0 para evitar confuiones 
  for (int k=co+1; k<18;k++){
    if (cont[k]==0){
    co +=1;
    año[k] = 0;
    mes[k] = 0;
    dia[k] = 0;
    hotel[k] = 0;
    cama[k] = 0;
    }
  }    
  imprimir(año,mes,dia,hotel,cama,16);  
}

void Turismo::seleccionar(const int Ho) const
{
  int tam=1,n1[16]; 
  for (int i = 1; i<16 ;i++){
    if (Ho==hotel[i]){
    n1[tam]=cama[i];
    tam+=1;
    }
  }
  cout << "numero_de_habitacion. Hotel_code: " <<Ho<< endl;
  for (int i=1; i< tam  ; i++){
  cout<<n1[i]<<endl;
  }
  
  //si hotel invalido
  if (tam==1){
  cout<< "El hotel no esta registrado"<<endl;
  }
}

void Turismo::estadistico() const
{
  //sacan repetidos
  int cont[16]={0};
  for (int i=1; i<16 ; i++){
    for (int j=1+i; j<17 ; j++){ 
      if (hotel[i]==hotel[j] ){
      cont[j]=j; 
      } 
    }     
  }
  int hoteles[16]={0};
  int co=0;
  for (int k=1; k<16;k++){
    if (cont[k]==0){
    co +=1;
    hoteles[co] = hotel[k];
    }
  }
  // contamos
  int ctt[16]={0};
  for (int l = 1; l<16; l++){
    for (int m = 1; m<co+1; m++){
      if(hotel[l]==hoteles[m]){
        ctt[m]+=1;
      }
    }
  }
  
  for (int n = 1; n<co+1 ;n++){
  cout<<"Hotel "<<hoteles[n]<< " tiene en total "<<ctt[n]<<" cama(s) distintas"<<endl;
  }  
}

void Turismo::contar(const int dd, const int mm, const int aa) const
{
  //sacan repetidos
  int cont[16]={0};
  for (int i=1; i<16 ; i++){
    for (int j=1+i; j<17 ; j++){ 
      if (dia[i]==dia[j] && mes[i]==mes[j] && año[i]==año[j]){
      cont[j]=j; 
      } 
    }     
  }
  int DI[16]={0},ME[16]={0},AN[16]={0};
  int co=0;
  for (int k=1; k<16;k++){
    if (cont[k]==0){
    co +=1;
    ME[co] = mes[k];
    AN[co] = año[k];
    DI[co] = dia[k];
    }
  }
  // contamos
  int ctt[16]={0};
  for (int l = 1; l<16; l++){
    for (int m = 1; m<co+1; m++){
      if(dia[l]==DI[m] && mes[l]==ME[m] && año[l]==AN[m] ){
        ctt[m]+=1;
      }
    }
  }
  int inv = 0;
  for (int n = 1; n<co+1 ;n++){
    if (dd==DI[n] && mm==ME[n] && aa==AN[n]){
      inv += 1; 
      cout<<"La Fecha: "<<aa<<"/"<<mm<<"/"<<dd<< " tiene en total "<<ctt[n]<<" cama(s) ocupadas"<<endl;
    }
  }
  // para fecha invalida
  if (inv!=1){
  cout<<"La Fecha: "<<aa<<"/"<<mm<<"/"<<dd<< " no esta registrada"<<endl; 
  }
}  

void Turismo::eliminarHotel(const int Ho) const
{
  int tam=1,n1[16],n2[16],n3[16],n4[16],n5[16]; 
  for (int i = 1; i<16 ;i++){
    if (Ho!=hotel[i]){
    n1[tam]=año[i];
    n2[tam]=mes[i];
    n3[tam]=dia[i];
    n4[tam]=hotel[i];
    n5[tam]=cama[i];
    tam+=1;
    }
  }
  imprimir(n1,n2,n3,n4,n5,tam);
  
  //si hotel invalido
  int tama = 1;
  for (int i = 1; i<16 ;i++){
    if (Ho==hotel[i]){
    tama+=1;
    }
  }
  if (tama==1){
  cout<< "No se eliminaron hoteles. El hotel no esta registrado "<<endl;
  }
}

string Turismo::getName()const
{
  return nameArchivo;
}
    


