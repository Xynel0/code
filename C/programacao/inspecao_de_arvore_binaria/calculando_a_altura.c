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



int altura (NoArv * x){
    if (x == NULL){
        return 0;
    }
    int e = altura(x->esq), d = altura(x->dir);
    if (e < d){
        return 1+d;
    }
    return 1+e;
}

int main() {
    resp = altura(p);
}
