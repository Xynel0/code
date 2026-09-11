// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 8

int L[N] = {2,3,4,1,2,3,4,6};

int resp;

int checa_ordenado(int L[], int i, int j);


// -- escreva seu código abaixo, não altere esta linha

int checa_ordenado(int L[], int i, int j){
    if (i == j-1){                    //verifica se chegou aos dois ultimos elementos do vetor
        if (L[i] <= L [j]){               //se os dois ultimos estiverem na ordem certa, retorna 1
            return 1;
        }
        else{                             //senão, retor na 0
            return 0;
        }
    }

    //nas demais iterações...
    int menor_ordenado = checa_ordenado (L, i+1, j);        //guarda em menor_ordenado o valor que indica se o vetor, dali para frente está ordenado.
    if (menor_ordenado == 0 || L[i] > L[i+1]){              //se não está ordenado dali pra frente OU se o valor L[i] estiver em desordem com relação ao próximo elemento, retorna 0.
        return 0;
    }
    else{                                                   //se estiver sem desordem entre os elementos analisados na iteração atual E não houver desordem dali para frente, retorna 1.
        return 1;
    }
}


int main() {
	resp = checa_ordenado(L, 0, N-1);   //atrubui à resp o valor que representa a ordenação do vetor
    printf("%d\n", resp);               //exibe o valor de resp apenas para acompanhamento
}
