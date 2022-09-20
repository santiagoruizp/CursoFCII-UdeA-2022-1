#include "hotel.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>

using namespace std;

int N=0; 
vector<int> Fecha_={};vector<int> Hotel_={};vector<int> Cama_={};

Hotel::Hotel(string Nombre ){ 
  nombre=Nombre;
}

void Hotel::leeProcesa(){
	FILE *_archivo;char cambio; 
	_archivo=fopen(nombre.c_str(),"r+"); //abriendo archivo
	if (!_archivo){ perror("El archivo no se pudo abrir\n");
		return;
	    }

	fclose(_archivo); 

	archivo>>_fecha>>_hotel>>_cama; //elimino las cabeceras
	while(archivo>>_fecha>>_hotel>>_cama){ Fecha_.push_back( atoi(_fecha.c_str()));
		Cama_.push_back( atoi(_cama.c_str()));
		Hotel_.push_back( atoi(_hotel.c_str()));
		N++;}
    	archivo.close();
    
    ifstream archivo; string _fecha, _hotel, _cama; 
	archivo.open(nombre.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl; 
		exit(1);
	}
}

void Hotel::nuevaListaSinDuplicados(){
	int contador=0;
    //recorro  cada i,j para encontrar duplicados
	for(int i=0; i<N; i++){
		for (int j=0;j<N;j++ ){
			if(i!=j && Fecha_[i]==Fecha_[j] && Cama_[i]==Cama_[j] && Hotel_[i]==Hotel_[j]){
				Fecha_[j]=0;Cama_[j]=0;Hotel_[j]=0; 
				contador++;
			}
		}
	}

	//con la ubicacion elimino ese dato
	for(int i=0; i<N; i++){
		if(Fecha_[i]==0){Fecha_.erase(Fecha_.begin()+i);
			Cama_.erase(Cama_.begin()+i);Hotel_.erase(Hotel_.begin()+i);
		}
	}
    //despues de eliminar consulto el tamaño 
	N=Hotel_.size();
}

void Hotel::seleccionar(int codigo){ vector <int> CamasVector={};
	nuevaListaSinDuplicados();
	
	for(int i=0; i<N;i++){
		if(Hotel_[i]==codigo){	
			CamasVector.push_back(Cama_[i]); //agrego camas al vector	
		}
	}
	cout<<" El hotel \t "<<codigo<<" tiene \t "<<CamasVector.size()<<"camas estas son... "<<endl;
	//imprimo especificamente esas camas
    for( int colchon:CamasVector){ cout<<colchon<<endl;}
}

void Hotel::estadistico(){vector <int> HotelesVector={};
	nuevaListaSinDuplicados();

	for(int i=0; i<N; i++){
		HotelesVector.push_back(Hotel_[i]);
	}

	for(int i=0; i<N; i++){
		for (int j=0;j<N;j++ ){
			if(i!=j && HotelesVector[i]==HotelesVector[j]){HotelesVector[j]=0;
			}
		}
	}
    //elimino hoteles repetidos
	for(int i=0; i<HotelesVector.size(); i++){
		if(HotelesVector[i]==0){HotelesVector.erase(HotelesVector.begin()+i);
		}
	}

	//camas por hotel
	vector <int> camasxhotel={};	

	for(int i=0; i<HotelesVector.size();i++){ camasxhotel.push_back(0);
	}

	for(int j=0; j<HotelesVector.size();j++){
		for(int i=0; i<N;i++){
			if(Hotel_[i]==HotelesVector[j]){	camasxhotel[j]=camasxhotel[j]+1;
			}
		}
	}

	for(int i=0; i< HotelesVector.size(); i++){
		cout<<"en el hotel \t"<<HotelesVector[i]<<" cantidad de camas...\t "<<camasxhotel[i]<<endl;
	}
}

void Hotel::contar(int dia, int mes, int anio){
	nuevaListaSinDuplicados();
	string _fecha=to_string(anio)+"0"+to_string(mes)+"0"+to_string(dia);
	int _Fecha=atoi(_fecha.c_str());int ocupadas=0;

	for(int iteracion:Fecha_){
		if(iteracion==_Fecha){ocupadas++;}
	}
	if (ocupadas==0){
		cout<<"invalido"<<endl;
	}
	cout<<"En la fecha \t"<<_Fecha<<" camas ocupadas \t "<<ocupadas<<endl;
}

void Hotel::eliminarHotel(int codigo){ nuevaListaSinDuplicados();
	for(int i=0; i<N; i++){
		if(Hotel_[i]==codigo){Hotel_[i]=0;} //encuentra el hotel y lo marca un cero
	}

	for(int i=0; i<N; i++){
		if(Hotel_[i]==0){ //hotel marcado con cero es eliminado
			Fecha_.erase(Fecha_.begin()+i);Cama_.erase(Cama_.begin()+i);
			Hotel_.erase(Hotel_.begin()+i);
		}
	}

}