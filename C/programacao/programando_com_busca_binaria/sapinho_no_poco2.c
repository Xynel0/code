// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

int P = 800;
int S = 300;
int E = 100;

int resp;

// -- escreva seu código abaixo, não altere esta linha



int main() {
	resp = 0;
	int altura_anterior = 0;
	int altura_atual = 0;
	while(S - E >= 0){

		if(resp >= 1){
			S = S-10;
		}

		if (altura_atual + S >= P){
			++resp;
			printf("%d\n", resp);
			return 0;
		}

		altura_atual = altura_anterior +S -E;
		printf("%d | %d | %d | %d\n", resp, altura_anterior, S, altura_atual);
		altura_anterior = altura_atual;
		++resp;
	}
	resp = -1;
	printf("%d\n", resp);
}
