// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct NoArv{
	int valor;
	struct NoArv * esq;
	struct NoArv * dir;
} NoArv;


NoArv * p;

int k;





// -- escreva seu código abaixo, não altere esta linha



void rotacao_esq(NoArv * x){
	if (x == NULL || x->esq == NULL){
		printf("ERRO: Rotação impossível!\n");
		return;
	}
	NoArv * y = x->esq;
	x->esq = y->dir;
	y->dir = x;
	p = y;
}
int main() {
	for (int i = 0; i < k; ++i){
		rotacao_esq(p);
	}
}
