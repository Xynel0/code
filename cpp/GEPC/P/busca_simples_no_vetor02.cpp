#include <bits/stdc++.h>
using namespace std;
int main(){
    int vetor[10]; //declara um vetor de tamanho 10
    bool vetor_hunter[10]; //declara um vetor secundário que irá armazenar em quais índices houve correspondência com o valor buscado
    int x; //declara a variável x, que será o valor para busca
    int x_hunter = 0; //declara a variável que guardará a quantidade de vezes que x apareceu

    //percorre o vetor atribuindo valores a cada índice dele
    for (int i = 0; i < 10; ++i){
        cout << "insira o " << i + 1 << "º valor:\n";
        cin >> vetor[i];
    }

    //pede o valor a ser procurado
    cout << "insira o valor X:\n";
    cin >> x;

    //percorre o vetor original buscando x e o vetor_hunter, atribuindo 1 em caso de correspondência
    for (int i = 0; i < 10; ++i){
        vetor_hunter[i] = false; //torna o vetor_hunter[i] = false antes de qualquer operação
        //se o vetor[i] corresponde a x, adiciona 1 a variável x_hunter, marcando quantas vezes x aparaceu e torna vetor_hunter=true, marcando nele quais os índices nos quais x apareceu
        if(vetor[i] == x){
            ++x_hunter;
            vetor_hunter[i] = true;
        }
    }
    //se x_hunter não tiver tido alteração, x não foi encontrado no vetor, então, é imprimida a mensagem solicitada
    if(x_hunter == 0){
        cout << "Mia x\n";
    }
    //se houve alteração...
    else{
        cout << x_hunter << endl; //...imprime o número de vezes que x apareceu
        //percorre o vetor_hunter e imprime os índices que estiverem verdadeiros.
        for (int i = 0; i < 10; ++i){
            if(vetor_hunter[i] == true){
                cout << i << " ";
            }
        }
        cout << endl; //finaliza uma linha para fins de organização
    }
}
