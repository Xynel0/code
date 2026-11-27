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






// -- escreva seu código abaixo, não altere esta linha



NoArv * poda(NoArv * x){
    if (x == NULL) return NULL;
    if (x->esq == NULL && x->dir == NULL){
        free(x);
        return NULL;
    }
    else{
        x->esq = poda(x->esq);
        x->dir = poda(x->dir);
        return x;
    }
}
int main() {
    p = poda(p);
}
