#include<iostream>
#include<iomanip>
#include<cmath>
#include <fstream>
#include <cstdlib> // En caso de error en la lectura permite que el programa se salga
#include <string>
#include <iomanip> // necesario para el formato de salida

#include "EDP_Expo.h"

WaveSol::WaveSol(double h_int, double k_int, double r_int, 
        double (*func1)(double), double (*func2)(double)): f_x(func1), g_x(func2) //Inicializa el constructor
{
    h=h_int;
    k=k_int;
    r=r_int;
}

void WaveSol::resultado() // Resuelve la ecuacion de onda
{
    double malla[11][11];
    int j, i;
    
    for (j=0;j<11;j++)
    {
        for (i=0;i<11;i++)
        {
            if (j==0)
            {
                if (i==0 || i==10)
                    malla[j][i]=0;
                else
                malla[j][i]=f_x(i*0.1);   
            }            
            if (j==1)
            {
                if (i==0 || i==10)
                    malla[j][i]=0;  
                else
                    malla[j][i]=(1-pow(r,2))*(f_x(i*h)) + k*(g_x(i*h)) + k*pow(r,2)*(f_x((i-1)*h)+f_x((i+1)*h));
            }
            if (j>1)
            {
                if (i==0 || i==10)
                    malla[j][i]=0;
                else
                    malla[j][i]=(2-2*pow(r,2))*malla[j-1][i]+pow(r,2)*(malla[j-1][i+1]+malla[j-1][i-1])-malla[j-2][i];         
            }            
        }
    }
    print(malla);
    return;
}

void WaveSol::print(const double matriz[11][11]) // Mostrara la informacion en pantalla en una Tabla y exportara el archivo de la solucion 
{
    cout<<setw(109)<<setfill('-')<<'\n'<<setfill(' ');
    cout<<"| "
        <<left<<setw(6)<<"  t"<<"|"
        <<left<<setw(8)<<"   x_0"<<"|"
        <<left<<setw(8)<<"   x_1"<<"|"
        <<left<<setw(8)<<"   x_2"<<"|"
        <<left<<setw(8)<<"   x_3"<<"|"
        <<left<<setw(8)<<"   x_4"<<"|"
        <<left<<setw(8)<<"   x_5"<<"|"
        <<left<<setw(8)<<"   x_6"<<"|"
        <<left<<setw(8)<<"   x_7"<<"|"
        <<left<<setw(8)<<"   x_8"<<"|"
        <<left<<setw(8)<<"   x_9"<<"|"        
        <<left<<setw(8)<<"   x_10"<<"|";
    cout<<setw(109)<<setfill('-')<<'\n'<<setfill(' ')<<'\n';
    cout<< setiosflags(ios::showpoint)
        << setprecision(3);
    int num=0;
    while(num<11)
    {
        cout<<"| "
            <<setw(6)<<num*0.05<<"|"
            <<right<<setw(8)<<matriz[num][0]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][1]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][2]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][3]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][4]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][5]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][6]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][7]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][8]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][9]<<fixed<<"|"
            <<right<<setw(8)<<matriz[num][10]<<fixed<<"|"
            <<endl;
        num++;
    }
    cout << setw( 108 ) << setfill( '-' ) << '-' << setfill( ' ' )<<endl;

    // Generacion del archivo
    string filename="onda.txt";
    //string filename="ondaE2.txt";
    ofstream outFile;

    outFile.open(filename.c_str());

    if (outFile.fail())
    {
        cout<<"\nEl archivo no pudo ser abierto"<<endl;
        exit(1);  
    }

    outFile << setiosflags(ios::fixed)
            << setiosflags(ios::showpoint)
            << setprecision(3);

    int num1, num2;
    for (num1=0;num1<11;num1++)
    {       
    outFile<<matriz[num1][0]<<","
           <<matriz[num1][1]<<"," 
           <<matriz[num1][2]<<"," 
           <<matriz[num1][3]<<"," 
           <<matriz[num1][4]<<"," 
           <<matriz[num1][5]<<"," 
           <<matriz[num1][6]<<"," 
           <<matriz[num1][7]<<"," 
           <<matriz[num1][8]<<"," 
           <<matriz[num1][9]<<","
           <<matriz[num1][10]<<endl;         
    }  

    outFile.close();
    cout<<"El archivo fue creado con exito"<<endl;  

    return;
}