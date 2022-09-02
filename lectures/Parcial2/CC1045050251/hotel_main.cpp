#include "hotel_interfaz.cpp"
#include <iostream>
using namespace std;

int main(){
	int opcion;
	Hotel consulta1("camas_hotel.txt"); 
	consulta1.leeProcesa();
	do{	cout<<" \n "<<endl;
	cout<<" 1- contenido del archivo cargado "<<endl;
	cout<<" 2- lista de hoteles sin repeticiones "<<endl;
	cout<<" 3- consulta de camas por codigo de hotel"<<endl;
	cout<<" 4- camas distintas por hotel"<<endl;
	cout<<" 5- camas ocupadas por fecha"<<endl;
	cout<<" 6- Eliminar todo un hotel por codigo"<<endl;
	cout<<" 7- Salir del programa "<<endl;
	cout<<"Seleccione una opción"<<endl;
	cout<<"\n"<<endl;cin>>opcion;
	
		switch(opcion){
			case 1:
				cout<<"\n Archivo cargado \n"<<endl;
				cout << left<< setw( 10 ) <<"Fecha"<<left<< setw( 13 ) << "Hotel"<< left <<setw( 7 )<< "Cama"<< endl;
				for(int i=0; i<Fecha_.size();i++){cout << left<< setw( 10 ) <<Fecha_[i]<<left<< setw( 13 ) << Hotel_[i]<< left <<setw( 7 )<< Cama_[i]<< endl;	
				}
				break;
			case 2:
				consulta1.nuevaListaSinDuplicados();
				cout<<"\nArchivo sin repeticiones \n"<<endl;
				cout << left<< setw( 10 ) <<"Fecha"<<left<< setw( 13 ) << "Hotel"<< left <<setw( 7 )<< "Cama"<< endl;
				for(int i=0; i<N;i++){cout << left<< setw( 10 ) <<Fecha_[i]<<left<< setw( 13 ) << Hotel_[i]<< left <<setw( 7 )<< Cama_[i]<< endl;
				}
				break;
			case 3:
				int codigoconsulta;
				cout<<"Datos del hotel segun codigo"<<endl;
				cin>>codigoconsulta; consulta1.seleccionar(codigoconsulta);
				break;
			case 4:
				consulta1.estadistico(); break;
			case 5:
				int dia, mes, anio;
				cout<<"Ingrese fecha en formato aaaa,mm,dd"<<endl;
				cin>>anio;cin>>mes; cin>>dia;
				consulta1.contar(dia,mes,anio); break;
			case 6:
				int codigoconsulta2;
				cout<<"código del hotel \t"<<endl; cin>>codigoconsulta2;
				consulta1.eliminarHotel(codigoconsulta2);
				break;
			case 7: 
				break;
			 default:
       				 cout<<"esa opcion no existe"<<endl;
		}
	}
	while (opcion!=7);	
	return 0;
}