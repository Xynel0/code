//recebe uma sequência de 10 números e os imprime na ordem inversa à do recebimento
#include <bits/stdc++.h>
using namespace std;
int main(){
    int lista[10]; //define o vetor lista com 10 elementos

    //atribui a cada elemento de "lista" o valor inserido
    for (int i = 0; i < 10; ++i){
        cout << "insira o " << i + 1 << "º número:\n";
        cin >> lista[i];
    }

    //para cada i, contando de 9 a 0, imprime o valor alocado na posição i
    for (int i = 9; i >= 0; --i){
        cout << lista[i] << endl;
    }
}
