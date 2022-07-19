#include<iostream>
#include<cstdlib>
using namespace std;

float dT( float T_s, float T_a ) // función para la diferencia de temperatura
{
        return((T_s - T_a));
}

float area(float r) // función para calcular el área del circulo 
{
        return(3.14 * r * r);
}
float area2(float b,float a) // función para calcular el área de la elipse
{
        return(3.14 * b * a);
}
float area3(float l,float c) // Para la parte b, simplemente se escoge el area del rectangulo y se ingresan los datos 0.002m (en metros) con el fin de que las unidades de la tasa de la transferencia de calor sean correctas.
{
        return (l * c);
}
int main()
{
        float b,a,r,l,c,T_s,T_a;
        const float H= 8.7; // unidades de H son la indicadas en el libro
        int ch;
         

        do
        {
                cout<<"\n\n *****Posibilidades***** \n";
                cout<<"\n 1. Area of Circle";
                cout<<"\n 2. Area of Ellipse";
                cout<<"\n 3. Area of Rectangle";
                cout<<"\n 4. Exit";
                cout<<"\n\n Enter Your Choice of surface area : ";
                cin>>ch;
                cout<<"\n Enter the temperatures T_s and T_a: "; // ingresando las temperaturas en este punto se evita hacerlo en cada caso 
                cin>>T_s>> T_a;// Después de darle exit se debe poner los valores de las temperaturas por defecto
                

                switch(ch)
                {
                        case 1:
                        {
                                cout<<"\n Enter the Radius of Circle : ";
                                cin>>r;
                                //cout<<"\n Enter the temperatures : ";
                                //cin>>T_s>> T_a;
                                cout<<"\n Area of Circle : "<<area(r);
                                cout<<"\n Heat : "<<H*dT(T_s,T_a)*area(r);
                                break;
                        }
                        case 2:
                        {
                                cout<<"\n Enter the length of semiaxis a and b of Ellipse : ";
                                cin>>b>>a;
                                cout<<"\n Area of Triangle : "<<area2(b,a);
                                cout<<"\n Heat : "<<H*dT(T_s,T_a)*area2(b,a);
                                break;
                        }
                        case 3:
                        {
                                cout<<"\n Enter the Length & Bredth of Rectangle : ";
                                cin>>l>>c;
                                cout<<"\n Area of Rectangle : "<<area3(l,c);
                                cout<<"\n Heat : "<<H*dT(T_s,T_a)*area3(l,c);
                                break;
                        }
                        case 4:
                                exit(0);
                        default:
                                cout<<"\n Invalid Choice... ";
                }
        }while(ch!=4); // Se realiza el ciclo mientras no se escoja la opción 4 
        return 0;
}