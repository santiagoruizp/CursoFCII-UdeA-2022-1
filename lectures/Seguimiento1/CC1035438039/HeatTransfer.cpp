//
// Created by kevin on 8/06/22.
//

#include <cmath>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "HeatTransfer.h"

HeatConvectionTransfer::HeatConvectionTransfer() : AIRCONV(8.7) {}

double HeatConvectionTransfer::airHeatTransferRate() {

    cout << "This method evaluated the heat transfer rate of a surface in air in units of Watts." << endl;
    cout << "You need to give the type of surface area (for calculated the area): 1 for rectangular area, 2 for elliptical and 3 to give the value of the area (all in meters or meters^2)." << endl;
    cout << "Also need the temperature of the ambient and the surface, both in celcius." << endl;
    cout<< "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    double surfaceTemperature;
    cout << "Enter the surface temperature in celcius: " << endl;
    cin >> surfaceTemperature;

    double ambientTemperature;
    cout << "Enter the ambient temperature in celcius: " << endl;
    cin >> ambientTemperature;

    int typeArea;
    cout << "Enter the type of area: " << endl;
    cin >> typeArea;

    double result;

    if (typeArea == 1){

        cout << "Rectangular area was selected." << endl;

        double width;
        double heigh;
        double area;

        cout << "Enter the width in meters:" <<  endl;
        cin >> width;
        cout << "Enter the heigh in meters:" <<  endl;
        cin >> heigh;

        area = width *heigh;

        result = AIRCONV*area*(surfaceTemperature - ambientTemperature);

    }else if (typeArea == 2){

        cout << "Elliptical area was selected." << endl;

        double majorAxii;
        double minorAxii;
        double area;

        cout << "Enter the major axis in meters:" <<  endl;
        cin >> majorAxii;
        cout << "Enter the minor axis in meters:" <<  endl;
        cin >> minorAxii;

        area = majorAxii * minorAxii * M_PI;

        result = AIRCONV*area*(surfaceTemperature - ambientTemperature);
    }else if(typeArea == 3){

        cout << "General area selected." << endl;

        double area;

        cout << "Enter the area in meters^2:" <<  endl;
        cin >> area;

        result = AIRCONV*area*(surfaceTemperature - ambientTemperature);
    }else{
        cout << "Enter a valid type of area" << endl;
        result = 0;
    }

    cout << "The heat transfer rate of the surface in the air is (in units of Watts): " << endl;

    return result;
}


