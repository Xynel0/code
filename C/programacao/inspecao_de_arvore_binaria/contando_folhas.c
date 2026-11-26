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



int conta_folhas(NoArv * x){
    if (x == NULL){
        return 0;
    }
    if (conta_folhas(x->dir) + conta_folhas(x->dir) == 0){
        return 1;
    }
    return conta_folhas(x->esq) + conta_folhas(x->dir);
}
int main() {
    resp = conta_folhas(p);
}
