#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; //define a variável que armazena quantos números serão sorteados
    int pontos; //define a variável que armazena os pontos para serem imprimidos ao final
    int seq_atual = 0; //define a variável que armazena o número da sequência que está sendo considerada (muda cada vez que um número sorteado é diferente do anterior, ou seja, uma nova sequência inicia-se)
    int n_da_sequencia; //define a variável que armazena o número que se repete na sequencia que estiver sendo considerada
    
    //recebe n
    cout << "insira o número n:\n";
    cin >> n;

    //define com base em n...
    int numeros_sorteados[n]; //vetor para armazenar na ordem cada número sorteado
    int pontos_da_sequencia[n]; //vetor com n posições para armazenar os pontos da sequência que estiver sendo considerada
    
    //define os pontos de todas as sequências como 1. no pior dos casos a pessoa não forma sequências, ou seja, forma n sequências de 1
    for(int i = 0; i < n; ++i){
        pontos_da_sequencia[i] = 1;
    }

    //recebe os números sorteados e os organiza no vetor numeros_sorteados
    for(int i = 0; i < n; ++i){
        cout << "insira o " << i + 1 << "º valor:\n";
        cin >> numeros_sorteados[i];
    }

    //a primeira sequência considerará o primeiro número recebido no sorteio
    n_da_sequencia = numeros_sorteados[0];

    //como n_da_sequência é igual a numeros_sorteados[0], e o ponto referente a isso já foi atribuído na definição de pontos, o for aqui começa em 1
    //percorre todo o vetor de números sorteados
    for(int i = 1; i < n; ++i){
        //se o número da sequência atual for igual ao número de índice i do vetor de números sorteados, a sequência atual ganha mais um ponto
        if(n_da_sequencia == numeros_sorteados[i]){
            ++pontos_da_sequencia[seq_atual];
        }
        //do contrário, o número da sequência é trocado, a sequência atual mantém seus pontos, mas uma nova sequência tem sua contagem de pontos iniciada
        else{
            n_da_sequencia = numeros_sorteados[i];
            ++seq_atual;
        }
    }
    //com cada sequência tendo seus pontos contados no vetor pontos_da_sequencia, vemos qual das sequências tem maior pontuação e atribuimos o valor dessa pontuação ao valor da pontuação final
    pontos = pontos_da_sequencia[0];
    for(int i = 0; i < n; ++i){
        if(pontos_da_sequencia[i] > pontos){
            pontos = pontos_da_sequencia[i];
        }
    }
    //por fim, imprimimos o valor da pontuação total
    cout << "pontos:\n" << pontos << endl;
}
