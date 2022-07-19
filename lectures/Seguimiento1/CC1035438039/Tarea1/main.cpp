#include <iostream>
#include <iomanip>


using std::cout;
using std::endl;
using std::setprecision;
using std::scientific;

#include "HeatTransfer.h"

int main() {
    HeatConvectionTransfer hct;

    cout << setprecision(2) << scientific << hct.airHeatTransferRate()<< endl;

    return 0;
}
