#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    
    int n, i12; // n será o número de acionamentos e i12 receberá o número referente ao interruptor acionado (1 ou 2)
    
    bool A = 0, B = 0; // A e B guardarão o estado atual de cada lâmpada
    cout << "numero de acionamentos:" << endl; 
    cin >> n; // lê o número de acionamentos

    // valida se n atende às restrições do problema (2 <= n <= 10^5)
    if (n >= 2 && n <= 100000){
        cout << "ordem dos acionamentos:" << endl;

        // para cada um dos n acionamentos, recebe o número do interruptor acionado
        for (int i = 0; i < n; i++){
            cin >> i12;

            // decide o que fazer com os valores de A e B baseando-se no interruptor acionado
            if (i12 == 1){
                A = !A;
            }
            else if (i12 == 2){
                A = !A;
                B = !B;
            }
            else{
                cout << "entrada inválida";
            }
        }

        // imprime os resultados
        cout << "Resultados:" << endl << A << endl << B << endl;
    
    }
    else{
        cout << "quantidade de acionamentos inválida" << endl;
    }
}
