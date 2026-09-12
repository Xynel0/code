// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 8

int L[N] = {2,3,4,1,2,3,4,6};

void transforma(int L[], int i, int j);

// -- escreva seu código abaixo, não altere esta linha

void transforma(int L[], int i, int j){
	if (i != j){                          //se o elemento analisado não for o ultimo chama a função com i+1
		transforma(L, i+1, j);            //segue chamando até o ultimo elemento, com o qual nada é feito.
		L[i] = L[i+1] + L[i];             //quando a função chega ao ultimo elemento e nada é feito, ao voltar, atribui a L[i] o valor à frente mais o valor atual de L[i]
	}                                     // conforme a função volta, soma sempre o próximo com o próprio elemento, conforme o problema pede.
}


int main() {

	for(int i = 0; i < N; ++i){
		printf("%d ", L[i]);
	}
	printf("\n");

	transforma(L, 0, N-1);

	for(int i = 0; i < N; ++i){
		printf("%d ", L[i]);
	}
	printf("\n");
}
