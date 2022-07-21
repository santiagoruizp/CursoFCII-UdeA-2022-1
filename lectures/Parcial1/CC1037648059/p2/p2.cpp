#include <iostream>
#include <vector>

std::vector<int> hallarDivisores(int n){
    std::vector<int> divisores;
    for (int i = 1; i < n; ++i) {
        if ( n % i == 0){
            divisores.push_back(i);
        }
    }
    return divisores;
}

int sumarDivisores(int n){
    std::vector<int> divisores = hallarDivisores(n);
    int suma = 0;
    for (int divisor : divisores) {
        suma += divisor;
    }
    return suma;
}

void esPerfecto(int n){
    int sumaDivisores = sumarDivisores(n);
    if (n == sumaDivisores){
        std::cout << "El numero " << n << " es perfecto: ";
        for (int divisor : hallarDivisores(n)) {
            if (divisor != hallarDivisores(n).at(hallarDivisores(n).size() - 1)){
                std::cout << divisor << " + ";
            }else{
                std::cout << divisor << " = " << n << std::endl;
            }
        }
    }
//    else{
//        std::cout << "El numero " << n << " no es perfecto: ";
//        for (int divisor : hallarDivisores(n)) {
//            if (divisor != hallarDivisores(n).at(hallarDivisores(n).size() - 1)){
//                std::cout << divisor << " + ";
//            }else{
//                std::cout << divisor << " != " << n << std::endl;
//            }
//        }
//    }
}

int main() {
    for (int i = 1; i < 10000; ++i) {
        esPerfecto(i);
    }
    return 0;
}