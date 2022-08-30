#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <vector>
#include <algorithm>  
#include <cmath>

using namespace std;

class DatosHoteles {

	private:
		string nombre;
		vector <string> file;
		vector <string> modifile;
		
	public:
		DatosHoteles(string); //No le estoy poniendo cuidado a usar const, REVISAR.
		void leeProcesa(); //Metodo que lee el archivo y lo almacena en la memoria.
		void nuevaListaSinDuplicados();
		vector <string> seleccionar(int);
		void estadistico();
		int contar(int);
		void impr();

};

DatosHoteles::DatosHoteles(string _nombre){
	nombre = _nombre;
	leeProcesa(); //Se ejecuta la función de una vez.
};

void DatosHoteles::leeProcesa(){
	ifstream archivo;
	string texto;
	
	archivo.open("camas_hotel.txt",ios::in); //abrimos en modo lectura.
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
	} 
	
	while (!archivo.eof()){ //Mientras no sea el final del archivo
		getline(archivo,texto);
		file.push_back(texto);
	}
	
	archivo.close();
}

void DatosHoteles::nuevaListaSinDuplicados()
{
	modifile = file;
  auto end = modifile.end();
  for (auto it = modifile.begin(); it != end; ++it) {
    end = remove(it + 1, end, *it);
  }
  modifile.erase(end, modifile.end());
}

vector<string> DatosHoteles::seleccionar(int n){
	vector <string> vector3;
	int d1 = n%10; //Se calculan los digitos del entero que representa el codigo del hotel
	int d2 = (n/10)%10;

	for (string i: modifile){
		int a = i[9]-48;   //Se transforman los caracteres correspondientes al codigo del hotel en enteros
		int b = i[10]-48;
		if(a == d2 && b == d1 ){
			vector3.push_back(i.substr(12, 3));      //Se selecciona la parte correspondiente a los datos de las camas cuando el codigo es correcto
		}
	}

	return vector3;
}

void DatosHoteles::estadistico(){
	vector <int> data(10,0);
	
	for (int j = 11; j<=20; j++){
		int d1 = j%10;
		int d2 = (j/10)%10;
		for(string i: modifile){
			int a = i[9]-48;
			int b = i[10]-48;
			if(a == d2 && b == d1 ){
				data[j-11]+=1;
			}
		}
	}
	data[0]= data[0]-1; //Le quitamos un uno que se agrega por la primera fila.
	for(int i = 0; i<=9; ++i){
		if(data[i] != 0){
			cout<<"El hotel "<<i+11<<" tiene en total "<<data[i]<<" camas distintas"<<endl;
		}
	}
}

void DatosHoteles::impr(){
	for(string i: modifile){
		cout<<i<<' '<<endl;
	}
}

int DatosHoteles::contar(int n){
	int cuenta = 0;
	
	vector <int> N(8);
	for (int l=0;l<=7;++l){
		N[l] = (n/int(pow(10,7-l)))%10;
		//cout<<N[l]<<endl;
	}


	for (string j: modifile){
	
		vector <int> V(8);
		for(int k=0;k<=7;++k){
			V[k] = j[k]-48;
		}
		if (N == V){
			cuenta+=1;
		}	
	}
	return cuenta;
	
}






int main(){
	DatosHoteles hotel("Desktop/Computacional/Seguimiento 2/camas_hotel.txt");
	hotel.nuevaListaSinDuplicados();
	hotel.impr();
	hotel.estadistico();
	hotel.seleccionar(20);
	cout<<hotel.contar(20210101)<<endl;
	return 0;
}
