#include "punto2_inter.cpp"
#include <iostream>
using namespace std;

int main(){
	int opcion;
	Hotel h1("camas_hotel.txt"); //sea crea el objeto. 
	h1.leeProcesa();
	cout<<"\n Este programa le permite extraer y modificar información de un archivo, elija una de las siguientes acciones\n"<<endl;
	do{
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<" 1) mostrará el contenido del archivo que se cargó "<<endl;
	cout<<" 2) genera una nueva lista de la informació inicial pero sin repetidos "<<endl;
	cout<<" 3) a partir de un código de un hotel pasado como parámetro, creará un nueva lista únicamente con los datos de las camas del hotel referido."<<endl;
	cout<<" 4) permite mostrar en pantalla la cantidad de camas registradas por cada hotel."<<endl;
	cout<<" 5) dada una fecha (dia, mes, año) retorna la cantidad de camas ocupadas existentes de esa fecha."<<endl;
	cout<<" 6) dado un identificador de hotel eliminará todas las ocurrencias asociadas a dicho hotel."<<endl;
	cout<<" 7) Salir del programa "<<endl;
	cout<<"Ingrese una opción"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"\n*------------EL archivo a procesar es:-----------* \n"<<endl;
				cout << left<< setw( 10 ) <<"Fecha"<<left<< setw( 13 ) << "Hotel"<< left <<setw( 7 )<< "Cama"<< endl;
				for(int i=0; i<Fecha.size();i++){
					cout << left<< setw( 10 ) <<Fecha[i]<<left<< setw( 13 ) << Hotell[i]<< left <<setw( 7 )<< Cama[i]<< endl;	
				}
				break;
			case 2:
				h1.nuevaListaSinDuplicados();
				cout<<"\n*------------La información depurada es:-----------* \n"<<endl;
				cout << left<< setw( 10 ) <<"Fecha"<<left<< setw( 13 ) << "Hotel"<< left <<setw( 7 )<< "Cama"<< endl;
				for(int i=0; i<N;i++){
					cout << left<< setw( 10 ) <<Fecha[i]<<left<< setw( 13 ) << Hotell[i]<< left <<setw( 7 )<< Cama[i]<< endl;
				}
				break;
			case 3:
				int codigo1;
				cout<<"Ingrese el código del hotel"<<endl;
				cin>>codigo1;
				h1.seleccionar(codigo1);
				break;
			case 4:
				h1.estadistico();
				break;
			case 5:
				int dia, mes, anio;
				cout<<"Ingrese una fecha en el formato de dia, mes, año"<<endl;
				cin>>dia;
				cin>>mes;
				cin>>anio;
				h1.contar(dia,mes,anio); //solo meses 1,3 y días 1,2 son válidos. (dia, mes, año)
				break;
			case 6:
				int codigo2;
				cout<<"Ingrese el código del hotel"<<endl;
				cin>>codigo2;
				h1.eliminarHotel(codigo2);
				break;
			case 7: 
				break;
			 default:
       				 cout<<"INGRESE UNA OPCIÓN VÁLIDA"<<endl;
		}
	}
	while (opcion!=7);	
	return 0;
}
