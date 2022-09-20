//Librerias
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


// Funciones prototipo
vector<string> leeProcesa();
vector<string> nuevaListaSinDuplicados(vector<string>);
vector<string> seleccionar(vector<string>, int);
vector<string> estadistico(vector<string>);
int contar(vector<string>, int , int , int );
vector<string> eliminarHotel(vector<string>, int);
void menu();

//Función principal
int main(){

	cout << "Bienvenid@ a la agencia de turismo" << endl;

	// Funciones de inicializacion
	vector < string > a=leeProcesa();
	vector<string> b=nuevaListaSinDuplicados(a);

	int opcion; // Variable que controlara la opcion del menu

	menu();

	cin >> opcion;

	while (opcion != 5) {
		switch (opcion)
		{
		case 0: {
			for (int i = 0; i < b.size(); i++) {
				cout << b[i] << endl;
			}
		}
			break;
		case 1: {
			int c1;
			cout << "Ingrese codigo del hotel: " << endl;
			cin >> c1;
			vector < string > c = seleccionar(b, c1);
			cout << "Camas disponibles:" << endl;
			for (int i = 0; i < c.size(); i++) {
				cout << c[i] << endl;

			}
		}
			break;



		case 2: {
			vector < string > d = estadistico(b);
			for (int i = 0; i < d.size(); i++) {
				cout << d[i] << endl;

			}
		}
			break;

		case 3: {
			int dia;
			int mes;
			int ao;
			cout << "Ingrese dia : ";
			cin >> dia;
			cout << endl;
			cout << "Ingrese mes : ";
			cin >> mes;
			cout << endl;
			cout << "Ingrese ao: ";
			cin >> ao;
			cout << endl;

			int e = contar(b, dia, mes, ao);

			cout << "Para la fecha elegida hay un numero de camas igual a : " << e << endl;
		}
			break;
		case 4: {

			int we;

			cout << "Ingrese codigo de hotel a eliminar: ";

			cin >> we;

			vector < string > f = eliminarHotel(b, we);

			for (int i = 0; i < f.size(); i++) {
				cout << f[i] << endl;

			}
		}
			break;

		default:
			cout << "La opcion escogida no es válida.\n";


		}
	
	cout << endl;
		menu();
		cin >> opcion;
	}
	

	cout << "Gracias por visitarnos !!" << endl;

	return 0;

}

// Se implementan las funciones prototipo

vector<string> leeProcesa() {
	ifstream archivo;

	string texto;
	archivo.open("camas_hotel.txt", ios::in);

	int m = 0;
	vector<string> info;
	while (!archivo.eof()) {

		getline(archivo, texto);
		
		if (m != 0) {
			info.push_back(texto);
			
		}
		m += 1;
	}
	
	archivo.close();
	
	return info;
	
	}


vector<string> nuevaListaSinDuplicados(vector<string> datos) {

	for (int i = 0; i < datos.size(); i++) {
		for (int j = i + 1; j < datos.size(); j++) {
			if (datos[i].compare(datos[j]) == 0)
				datos.erase(datos.begin() + j);

		}
		}
		

	return datos;
}

vector<string> seleccionar(vector<string> datos, int parametro) {

	const int c = datos[0].size(); //longitud de la cadena
	string para = to_string(parametro); //convertimos parametro a variable tipo cadena
	vector<string> nuevos_datos;

	for (int i = 0; i < datos.size(); i++) {
		string var;
		string cond;
		cond.push_back(datos[i][9]);
		cond.push_back(datos[i][10]);

		//cout << cond << endl;
		//cout << com.compare(para) << endl;
		
		if (cond.compare(para)==0) { // Condición codigo de hotel
			
			
			for (int j = c - 4; j < c; j++) {
				var.push_back(datos[i][j]);
				
				}
				
			nuevos_datos.push_back(var);
			}

	
	
	}
	return nuevos_datos;

}

vector<string> estadistico(vector<string> datos) {
	vector < int > codigos = { 11,14,15,16,17,19,20 };
	vector < string > inform;
	for (int i = 0; i < codigos.size(); i++) {
		int contar;
		contar = seleccionar(datos, codigos[i]).size();
		string d = "El hotel " + to_string(codigos[i]) + " tiene en total " + to_string(contar) + " cama(s) distintas";
		inform.push_back(d);
	}
	return inform;
}

int contar(vector<string> datos, int dia, int mes, int ao) {

	string fecha = to_string(ao) + "0" + to_string(mes) + "0" + to_string(dia);
	vector<string> nuevos_datos;
	const int c = datos[0].size();

	for (int i = 0; i < datos.size(); i++) {
		string var;
		string cond;
		cond.push_back(datos[i][0]);
		cond.push_back(datos[i][1]);
		cond.push_back(datos[i][2]);
		cond.push_back(datos[i][3]);
		cond.push_back(datos[i][4]);
		cond.push_back(datos[i][5]);
		cond.push_back(datos[i][6]);
		cond.push_back(datos[i][7]);

			//cout << cond << endl;
			//cout << com.compare(para) << endl;

		if (cond.compare(fecha) == 0) { // Condición codigo de hotel


			for (int j = c - 4; j < c; j++) {
				var.push_back(datos[i][j]);

				}

			nuevos_datos.push_back(var);
		}



		}

	return nuevos_datos.size();
}

vector<string> eliminarHotel(vector<string> datos, int codigo) {

	string para = to_string(codigo); //convertimos codigo a variable tipo cadena

	for (int i = 0; i < datos.size(); i++) {

		string cond;
		cond.push_back(datos[i][9]);
		cond.push_back(datos[i][10]);
		if (cond.compare(para) == 0)
			datos.erase(datos.begin() + i);


	}
	return datos;



}

void menu() {

	cout << "Elija una de las siguientes opciones (numero): " << endl;
	cout << "0. Ver informacion completa." << endl;
	cout << "1. Digite un codigo de hotel para ver cama(s) disponibles." << endl;
	cout << "2. Muestra cantidad de cama(s) registradas por hotel." << endl;
	cout << "3. Muestra cantidad de cama(s) para un (dia,mes,ao). " << endl;
	cout << "4. Elimina hoteles de un codigo determinado." << endl;
	cout << "5. Salir." << endl;
}



