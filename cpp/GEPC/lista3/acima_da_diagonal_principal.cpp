#include <bits/stdc++.h>
using namespace std;
int main(){
    string operacao;
    float matriz[12][12];
    float soma_acima_diagonal = 0;

    //recebe operação
    cin >> operacao;
    //recebe valores da matriz
    for(int i = 0; i < 12; ++i){
        for(int j = 0; j < 12; ++j){
            cin >> matriz[i][j];
        }
    }
    //realiza a soma dos elementos acima da diagonal principal
    for(int i = 0; i < 12; ++i){
        for(int j = i + 1; j < 12; ++j){
            soma_acima_diagonal = soma_acima_diagonal + matriz[i][j];
        }
    }
    //determina se será imprimida a soma ou a média
    if(operacao == "S"){
        cout << fixed << setprecision(1) << soma_acima_diagonal << endl;
    }
    else if(operacao == "M"){
        cout << fixed << setprecision(1) << soma_acima_diagonal / 66 << endl;
    }
}
