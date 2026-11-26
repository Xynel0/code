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


NoArv * p;

int resp;


// -- escreva seu código abaixo, não altere esta linha



int last; int is_first;
int checaArv(NoArv * x){
    if (x == NULL){
        return 1;
    }
    resp = checaArv(x->esq);
    if (resp == 0){
        return 0;
    }
    if (is_first){
        last = x->valor;
        is_first = 0;
    }
    else{
        if (x->valor < last){
            return 0;
        }
        last = x->valor;
    }
    resp = checaArv(x->dir);
}
int main() {
    is_first = 1;
    resp = 1;
    resp = checaArv(p);
}
