#include "punto2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include <vector>

using namespace std; 

Hotel::Hotel(string Nombre ){ 
  nombre=Nombre;
}

//variables global para guardar la información del archivo. 
int N=0; //filas de los vectores.
vector<int> Fecha={};
vector<int> Hotell={};
vector<int> Cama={};

void Hotel::leeProcesa(){ //función utilitaria. 
	//////cambia los ; por espacios en el archivo. 
	FILE *arch;
	char car; 
	arch=fopen(nombre.c_str(),"r+");
	if (!arch){
		perror("El archivo no se pudo abrir\n");
		return;
	    }
	    while (fscanf(arch,"%c",&car)!=EOF){
		if (car==';')
		{
		    fseek(arch, -1, SEEK_CUR);
		    fputc(' ', arch);
		    fflush(arch);
		}
	    }
	fclose(arch);
	///////////////////////////// vamos a pasar la información a vectores numéricos. 

	ifstream archivo; 
	
	archivo.open(nombre.c_str(),ios::in); //abriendo el archivo en modo lectura separado por espacios. 
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl; //verifica que exista el archivo
		exit(1);
	}
	string fecha, hotel, cama;
	
	archivo>>fecha>>hotel>>cama; //para que no guarde los títulos en el vector
	while(archivo>>fecha>>hotel>>cama){
		Fecha.push_back( atoi(fecha.c_str()) );
		Cama.push_back( atoi(cama.c_str()) );
		Hotell.push_back( atoi(hotel.c_str())  );
		N++;	
    	}
    	archivo.close();
}


void Hotel::nuevaListaSinDuplicados(){
	int R=0;
	for(int i=0; i<N; i++){
		for (int j=0;j<N;j++ ){
			if(i!=j && Fecha[i]==Fecha[j] && Cama[i]==Cama[j] && Hotell[i]==Hotell[j]){
				Fecha[j]=0;
				Cama[j]=0;
				Hotell[j]=0; 
				R++;
			}
		}
	}
	
	//Ahora vamos a eliminar los elementos repetidos:
	for(int i=0; i<N; i++){
		if(Fecha[i]==0){
			Fecha.erase(Fecha.begin()+i);
			Cama.erase(Cama.begin()+i);
			Hotell.erase(Hotell.begin()+i);
		}
	}
	
	N=Hotell.size(); //redefinimos la variable global del tamaño de los datos.
}

void Hotel::seleccionar(int codigo){
	nuevaListaSinDuplicados();
	vector <int> Camas={};
	for(int i=0; i<N;i++){
		if(Hotell[i]==codigo){	
			Camas.push_back(Cama[i]);	
		}
	}
	cout<<" Las camas que posee el hotel con código "<<codigo<<" son "<<Camas.size()<<": "<<endl;
	for( int linea:Camas){
		cout<<linea<<endl;
	}
}


void Hotel::estadistico(){
	nuevaListaSinDuplicados();
	vector <int> Hoteles={};
	//primero busquemos todos los hoteles diferentes

	for(int i=0; i<N; i++){
		Hoteles.push_back(Hotell[i]);
	}
	
	for(int i=0; i<N; i++){
		for (int j=0;j<N;j++ ){
			if(i!=j && Hoteles[i]==Hoteles[j]){
				Hoteles[j]=0;
			}
		}
	}
	
	for(int i=0; i<Hoteles.size(); i++){
		if(Hoteles[i]==0){
			Hoteles.erase(Hoteles.begin()+i);
		}
	}

	for(int i=0; i<Hoteles.size(); i++){
		if(Hoteles[i]==0){
			Hoteles.erase(Hoteles.begin()+i);
		}
	}
	//ahora contamos cuántas camas están asociadas al mismo hotel. 
	vector <int> camass={};	
	
	for(int j=0; j<Hoteles.size();j++){
		camass.push_back(0);
	}
	
	
	for(int j=0; j<Hoteles.size();j++){
		for(int i=0; i<N;i++){
			if(Hotell[i]==Hoteles[j]){	
				camass[j]=camass[j]+1;
			}
		}
	}
	
	for(int i=0; i< Hoteles.size(); i++){
		cout<<"Las camas registradas en el hotel "<<Hoteles[i]<<" son: "<<camass[i]<<endl;
	}
}

void Hotel::contar(int dia, int mes, int anio){
	nuevaListaSinDuplicados();
	string fechaa=to_string(anio)+"0"+to_string(mes)+"0"+to_string(dia);
	int Fechaa=atoi(fechaa.c_str());
	int ocupadas=0;
	for(int valor:Fecha){
		if(valor==Fechaa){
			ocupadas++;
		}
	}
	if (ocupadas==0){
		cout<<"La fecha que ingresó no es válida"<<endl;
	}
	cout<<"Las camas ocupadas en la fecha "<<Fechaa<<" son: "<<ocupadas<<endl;
}


void Hotel::eliminarHotel(int codigo){
	nuevaListaSinDuplicados();
	for(int i=0; i<N; i++){
		if(Hotell[i]==codigo){
			Hotell[i]=0;
		}
	}
	
//Ahora vamos a eliminar los elementos repetidos:
	for(int i=0; i<N; i++){
		if(Hotell[i]==0){
			Fecha.erase(Fecha.begin()+i);
			Cama.erase(Cama.begin()+i);
			Hotell.erase(Hotell.begin()+i);
		}
	}
	//tocó hacerlo dos veces, no sé porqué. 
	for(int i=0; i<Hotell.size(); i++){
		if(Hotell[i]==0){
			Fecha.erase(Fecha.begin()+i);
			Cama.erase(Cama.begin()+i);
			Hotell.erase(Hotell.begin()+i);
		}
	}

	cout<<"La información eliminando al hotel con código "<<codigo<<" es:"<<endl;
	cout << left<< setw( 10 ) <<"Fecha"<<left<< setw( 13 ) << "Hotel"<< left <<setw( 7 )<< "Cama"<< endl;
	for(int i=0; i<Hotell.size();i++){
	cout << left<< setw( 10 ) <<Fecha[i]<<left<< setw( 13 ) << Hotell[i]<< left <<setw( 7 )<< Cama[i]<< endl;
	}
}
