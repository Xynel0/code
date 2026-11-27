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




NoArv * endireita(NoArv * x){
    if (x == NULL){
        return NULL;
    }
    if (x->esq == NULL && x->dir == NULL){
        return x;
    }
    if(x->esq == NULL){
        x->dir = endireita(x->dir);
        return x;
    }
    NoArv * y = x->esq;
    x->esq = y->dir;
    y->dir = x;
    x = y;
    return endireita(x);

}
int main() {
    p = endireita(p);
}
