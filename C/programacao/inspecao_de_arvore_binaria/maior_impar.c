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


int resp;


// -- escreva seu código abaixo, não altere esta linha



int last;
void maiorimpar(NoArv * x){
    if (x == NULL){
        return;
    }
    maiorimpar(x->dir);
    if (resp != -1){
        return;
    }
    if (x->valor%2 != 0){
        resp = x->valor;
        return;
    }
    if (resp != -1){
        return;
    }
    maiorimpar(x->esq);
}
int main() {
    resp = -1;
    maiorimpar(p);
}
