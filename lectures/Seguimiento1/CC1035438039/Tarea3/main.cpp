#include <iostream>
#include <iomanip>


using std::cout;
using std::endl;
using std::setprecision;
using std::scientific;

#include "Exponencial.h"

int main() {
    Exponencial exponencial(1.0, 20);
    exponencial.getValor();

    return 0;
}
