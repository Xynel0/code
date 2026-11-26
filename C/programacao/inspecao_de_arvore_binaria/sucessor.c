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
int k;

int resp;


// -- escreva seu código abaixo, não altere esta linha



int sucessor(NoArv * x, int valor){
    NoArv * next = NULL;
    while(x != NULL && valor != x->valor){
        if (valor < x->valor){
            next = x;
            x = x->esq;
        }
        else{
            x = x->dir;
        }
    }
    if (x != NULL && x->dir != NULL){
        next = x->dir;
        x = x->dir->esq;
        while (x != NULL){
            next = x;
            x = x->esq;
        }
    }
    if (next == NULL){
        return -1;
    }
    return next->valor;
}

int main() {
    resp = sucessor(p, k);
}
