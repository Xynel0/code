// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 8

int L[N] = {2,3,4,1,2,3,4,6};

int resp;

int msc(int L[], int i, int j);


// -- escreva seu código abaixo, não altere esta linha

int msc(int L[], int i, int j){
	int k = i;
	int tam = 1;

	if (i == j){
		return 1;
	}
	else{
		while(k < j && L[k] <= L[k+1]){
			++tam;
			++k;
		}
		if (k < j){
			int x = msc(L, k + 1, j);
			return (tam > x) ? tam : x;
		}
		else{
			return tam;
		}
	}
}


int main() {
	resp = msc(L, 0, N-1);
	printf("%d\n", resp);
}
