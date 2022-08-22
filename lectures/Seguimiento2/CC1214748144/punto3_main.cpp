#include <iostream>
#include "punto3_inter.cpp"

using namespace std;


int main(){
	Fecha uno(23,10,2000); //donde no hay cambio de mes ni de año. 
	Fecha dos(31,8,2022); //si es un día en el que se cambia de mes pero no de año.	
	Fecha tres(31,12,2022); //si es un día en el que se cambia de mes y de año.	
	Fecha cuatro(29,2,2012); //si es un año viciesto;
	
	
	
	uno.diaSig();
	uno.mostrar();
	cout<<endl;
	dos.diaSig();
	dos.mostrar();
	cout<<endl;
	tres.diaSig();
	tres.mostrar();
	cout<<endl;
	cuatro.diaSig();
	cuatro.mostrar();
	cout<<endl;
	
	
	uno.~Fecha();
	dos.~Fecha();
	tres.~Fecha();
	cuatro.~Fecha();
}


