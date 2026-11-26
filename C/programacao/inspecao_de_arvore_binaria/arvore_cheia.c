// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h> //INT_MIN e INT_MAX
typedef struct NoArv{
	int valor;
	struct NoArv * esq;
	struct NoArv * dir;
} NoArv;

NoArv * criar_no(int valor, NoArv * esq, NoArv * dir){
	NoArv * no = malloc(sizeof(NoArv));
	no->valor = valor;
	no->esq = esq;
	no->dir = dir;
	return no;
}

int hmin(int N){
	int h = 0;
	N++;
	while(N>0){
		N = N/2;
		h++;
	}
	return h-1;
}

NoArv * p;

int resp;


// -- escreva seu código abaixo, não altere esta linha



void verifica_cheia(NoArv * x){
    if (x == NULL){
        return;
    }
    if ((x->esq != NULL && x->dir != NULL)){
        verifica_cheia(x->esq);
        verifica_cheia(x->dir);
    }
    else if (x->esq == NULL && x->dir == NULL){
        return;
    }
    else{
        resp = 0;
        return;
    }
}
int main() {
    resp = 1;
    verifica_cheia(p);
}
