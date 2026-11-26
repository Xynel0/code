// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct NoArv{
	int valor;
	struct NoArv * esq;
	struct NoArv * dir;
} NoArv;


NoArv * p;

int k = 2;

int resp;


// -- escreva seu código abaixo, não altere esta linha



void kesimo(NoArv * x, int * i){
    if (x == NULL){
        return;
    }
    kesimo(x->esq, i);
  	++ *i;
    if (*i == k){
        resp = x->valor;
        printf("%d\n", x->valor);
        return;
    }
    kesimo(x->dir, i);
}
int main() {
  	int i = 0;
  	kesimo(p, &i);
}
