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

typedef struct NoLista{
	int valor;
	struct NoLista * prox;
} NoLista;

NoLista * criar_no_lista(int valor, NoLista * prox){
	NoLista * no = malloc(sizeof(NoLista));
	no->valor = valor;
	no->prox = prox;
	return no;
}

int k = 2;

NoArv * p;

NoLista * q;



// -- escreva seu código abaixo, não altere esta linha



NoLista * last;
int is_bigger;
void encadeia_maiores(NoArv * x){
    if(x == NULL){
        return;
    }
    encadeia_maiores(x->esq);
    if (is_bigger == 0){
        if (x->valor >= k){
            is_bigger = 1;
            q = criar_no_lista(x->valor, NULL);
            last = q;
        }
    }
    else{
        last->prox = criar_no_lista(x->valor, NULL);
        last = last->prox;
    }
    encadeia_maiores(x->dir);
}
int main() {
    q = NULL;
    last = NULL;
    is_bigger = 0;
    encadeia_maiores(p);
}
