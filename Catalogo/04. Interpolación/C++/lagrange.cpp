/* ------------------------------------------------------------
 * @file: lagrange.cpp
 * @dependencias: GiNaC
 * @version 0.1
 * ------------------------------------------------------------*/

// [1] $ g++ lagrange.cpp -o lg.out -std=c++11 -I/usr/include/python3.8 -lpython3.8 
// [2] $ ./lg.out

#include <iostream>
#include <vector>
#include <cmath>
#include <ginac/ginac.h>

using namespace std;
using namespace GiNaC;


/**
 * @brief 
 * 
 * @param xv 
 * @param yv 
 * @return ex 
 */
ex lagrange(vector<double> xv, vector<double> yv){

    symbol x("x");
    int n = xv.size();
    ex poly = 0;

    for (int k = 0; k < n; k++){
        poly += yv[k] * lagrange_basis(xv,k);
    }

    return poly;
}


/**
 * @brief 
 * 
 * @param xv 
 * @param k 
 * @return ex 
 */
ex lagrange_basis(vector<double> xv, int k){
    
    symbol x("x");
    int n = xv.size();
    ex Lk = 1;

    for (int i = 0; i < n; i++){
        if (i != k){
            Lk *= (x - xv[i])/(xv[k] - xv[i]);
        }
    }

    return Lk;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
