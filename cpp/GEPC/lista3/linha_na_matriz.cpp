#include <bits/stdc++.h>
using namespace std;
int main(){
    //declarando elementos
    float matriz_muito_doida[12][12];
    int linha_da_matriz;
    string operacao;
    float soma_da_linha = 0;

    //recebendo entradas
    cin >> linha_da_matriz;
    cin >> operacao;
    for(int i = 0; i < 12; ++i){
        for (int j = 0; j < 12; ++j){
            cin >> matriz_muito_doida[i][j];
        }
    }

    for(int i = 0; i < 12; ++i){
        soma_da_linha = soma_da_linha + matriz_muito_doida [linha_da_matriz][i];
    }

    //determinar qual operação será feita
    if(operacao == "S"){
        cout << fixed << setprecision(1) << soma_da_linha << endl;
    }
    else if(operacao == "M"){
        cout  << fixed << setprecision(1) << soma_da_linha / 12 << endl;
    }
    else{
        cout << "entrada inválida" << endl;
    }
}
