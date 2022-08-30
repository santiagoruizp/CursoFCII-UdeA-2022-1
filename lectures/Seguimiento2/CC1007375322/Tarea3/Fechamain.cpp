/**Tarea3.
UTILIZANDO LAS TECNICAS DISCUTIDAS EN NUESTRO CURSO, POR FAVOR:
a) Defina una clase llamada "Fecha".
b) En la clase Fecha definida, debe incluir una función "diaSig()" que incremente una fecha en un día.
Pruebe su función para asegurarse que incrementa de manera correcta los dias en un nuevo mes y en un nuevo año.
c) Escriba un programa que pruebe su clase (se refiere a un main).*/

#include "Fecha.h"

int main(){

    //Probemos la clase creada y que incremente correctamente en los casos extremos
    //Nuevo año
    Fecha fecha1(12,31,2005);
    fecha1.diaSig();

    //año visiesto

    Fecha fecha2(2,29,2000);
    fecha2.diaSig();

    //último día del mes
    Fecha fecha3(1,31,2022);
    fecha3.diaSig();

    //Día normal del año
    Fecha fecha4(4,5,2005);
    fecha4.diaSig();


}
