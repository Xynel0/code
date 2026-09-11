// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 8

int L[N] = {2,3,4,1,2,3,4,6};

void remova_pares(int L[], int i, int j);

// -- escreva seu código abaixo, não altere esta linha

void remova_pares(int L[], int i, int j){
	if (i <= j){                                               //verifica se ainda há o que ser verificado e, se sim, prossegue.
		if (L[i] % 2 == 0){                                        //se o número atual for par
			for (int trocado = i; trocado < j; ++trocado){             //da variável atual até o limite menos 1, atribui à variável atual o valor da próxima.
				L[trocado] = L[trocado + 1];
			}
			L[j] = 0;                                                  //adiciona um 0 na ultima posição de análise da função
			remova_pares(L, i, j-1);                                   // chama a função novamente passando o valor i atual(pois o L[i] atual passou a ser l[i+1] devido ao for) e j-1, pois o j estará zerado.
		}
		else{
			remova_pares(L, i+1, j);                               // se não for par, vida que segue, chama a função com i + 1 de início.
	    }
	}
}


int main() {
	remova_pares(L, 0, N-1);
	for (int i = 0; i < N; ++i){   //
		printf("%d ", L[i]);       //    imprime a lista para acompanhamento dos resultados
	}                              //
	printf("\n");                  //
}
