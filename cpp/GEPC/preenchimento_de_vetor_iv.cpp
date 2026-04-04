#include <bits/stdc++.h>
using namespace std;
int main(){
    int valores[15];
    int pares[5];
    int impares[5];
    int valorpar = 0;
    int valorimpar = 0;

    //lê os 15 valores e organiza-os no vetor valores
    for (int i = 0; i < 15; i++)
    {
        cin >> valores[i];
    }

    //para cada um dos 15...
    for (int i = 0; i < 15; i++){
            //se o valor for par e o pares[] não estiver cheio
            if(valores[i] % 2 == 0 && (valorpar % 5 != 0 || valorpar == 0)){
                pares[valorpar] = valores[i];
                ++valorpar;
            }
            else if(valores[i] % 2 == 0){
                //imprimir vetor inteiro
                for (int j = 0; j < 5; ++j){
                    cout << "par[" << j << "] = " << pares[j] << endl;
                }
                pares[0] = valores[i];
                valorpar = 1;
            }
            //se o valor for impar e o impares[] não estiver cheio
            else if(valorimpar % 5 != 0 || valorpar == 0){
                impares[valorimpar] = valores[i];
                ++valorimpar;
            }
            else{
                for (int j = 0; j < 5; ++j){
                    cout << "impar[" << j << "] = " << impares[j] << endl;
                }
                impares[0] = valores[i];
                valorimpar = 1;
            }
        }
        for(int k = 0; k < valorimpar; ++k){
            cout << "impar[" << k << "] = " << impares[k] << endl;
        }
        for(int l = 0; l < valorpar; ++l){
            cout << "par[" << l << "] = " << pares[l] << endl;
        }
    }
