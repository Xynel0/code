#include <bits/stdc++.h>
using namespace std;

int quantidade_e_resto(int valorint, int valor_da_cedula, string tipo){
    int quantidade = floor(valorint/valor_da_cedula);
    cout << quantidade << tipo << fixed << setprecision(2) << valor_da_cedula / 100.00 << endl;
    valorint = valorint % valor_da_cedula;
    return valorint;
}

int main(){
    int valores_das_cedulas [12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    float entrada;
    int valorint;
    
    cin >> entrada;
    valorint = entrada * 100;

    cout << "NOTAS:" << endl;
    for(int i = 0; i < 6; ++i){
        valorint = quantidade_e_resto(valorint, valores_das_cedulas[i], " nota(s) de R$ ");
    }
    cout << "MOEDAS:" << endl;
    for(int i = 6; i < 12; ++i){
        valorint = quantidade_e_resto(valorint, valores_das_cedulas[i], " moeda(s) de R$ ");
    }
}