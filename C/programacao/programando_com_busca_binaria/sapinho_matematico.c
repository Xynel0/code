// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

int P = 200;
int E = 10;

int resp;


// -- escreva seu código abaixo, não altere esta linha



int da_ou_nao(int forca_inicial){
	int altura = 0;
	while (altura < P){
		if (forca_inicial < E){
			return -1;
		}
		altura += forca_inicial;

		if (altura >= P){
			return 1;
		}
		
		altura -= E;
		forca_inicial -= 10;
	}
}
int main() {
	int esquerda = 1, direita = P, meio;
	while (esquerda < direita){
		meio = da_ou_nao((esquerda + direita)/2);
		if (meio == 1){
			direita = (esquerda + direita)/2;
		}
		else{
			esquerda = ((esquerda + direita)/2) +1;
		}
	}
	resp = esquerda;
	printf("%d\n", resp);
}
