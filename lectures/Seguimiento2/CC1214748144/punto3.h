/*Tarea3.
UTILIZANDO LAS TECNICAS DISCUTIDAS EN NUESTRO CURSO, POR FAVOR:
a) Defina una clase llamada "Fecha".
b) En la clase Fecha definida, debe incluir una función "diaSig()" que incremente una fecha en un día.
Pruebe su función para asegurarse que incrementa de manera correcta los dias en un nuevo mes y en un nuevo año.
c) Escriba un programa que pruebe su clase (se refiere a un main)*/


#ifndef FECHA_H
#define FECHA_H

class Fecha{
	public:
		Fecha(int, int, int); //constructor
		~Fecha(); //destructor
		
		
		int getdia() const; /* funcioens getters. Para que la persona que vaya a hacer una clase heredera pueda acceder a las variables paramétricas privadas de la clase base.*/
		int getmes() const;
		int getanio() const;
		
		
		void diaSig();
		void mostrar();	
	private:
		int dia=1, mes=1, anio=2000; //se establecen valores por default. 
};

#endif
