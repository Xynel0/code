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
NoArv * q;
int resp;






// -- escreva seu código abaixo, não altere esta linha



typedef struct NoLista{
    int valor;
    struct NoLista * prox;
} NoLista;

NoLista * criarNoLista(int valor, NoLista * prox){
    NoLista * x = malloc(sizeof(NoLista));
    x->valor = valor;
    x->prox = prox;
    return x;
}

NoLista * last;
void em_ordem(NoArv * x){
    if (x == NULL){
        return;
    }
    em_ordem(x->esq);
    last->prox = criarNoLista(x->valor, NULL);
    last = last->prox;
    em_ordem(x->dir);
}

void libera_lista(NoLista * x){
    NoLista * prox;
    while (x != NULL){
        prox = x->prox;
        free(x);
        x = prox;
    }
}
int main() {
    NoLista * lista1 = criarNoLista(0, NULL);
    last = lista1;
    em_ordem(p);
    last = lista1;
    lista1 = lista1->prox;
    free(last);

    NoLista * lista2 = criarNoLista(0, NULL);
    last = lista2;
    em_ordem(q);
    last = lista2;
    lista2 = lista2->prox;
    free(last);

    resp = 1;
    NoLista * i = lista1, * j = lista2;
    while (i != NULL || j != NULL){
        if (i == NULL || j == NULL || i->valor != j->valor){
            resp = 0;
            libera_lista(lista1);
            libera_lista(lista2);
            return 0;
        }
        i = i->prox;
        j = j->prox;
    }
    libera_lista(lista1);
    libera_lista(lista2);
}
