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



int main() {
    if (p == NULL) return 0;
    NoArv * q = p;
    NoArv * last = NULL;
    while (q->esq != NULL){
        last = q;
        q = q->esq;
    }
    if(last == NULL){
        return 0;
    }
    last->esq = q->dir;
    q->dir = p;
    p = q;
}
