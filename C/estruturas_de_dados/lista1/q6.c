// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct NoLista{
	int valor;
	struct NoLista * prox;
} NoLista;

NoLista * criar_no(int valor, NoLista * prox){
	NoLista * no = malloc(sizeof(NoLista));
	no->valor = valor;
	no->prox = prox;
	return no;
}

NoLista * p;
NoLista * q;

void printa_lista(NoLista * item, char * nome){ //recebe um ponteiro para uma lista e a imprime
    printf("%s:\n", nome);
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

NoLista * merge(NoLista * p, NoLista * q){
    
    if (p == NULL){
        return q;
    }
    if (q == NULL){
        return p;
    }
    NoLista * r = NULL;
    NoLista * ultimo = NULL;
    while (p != NULL && q != NULL){
        NoLista * menor = NULL;
        if (p->valor < q->valor){
            menor = p;
            p = p->prox;
        }
        else{
            menor = q;
            q = q->prox;
        }
        if (ultimo == NULL){
            r = menor;
            ultimo = menor;
        }
        else{
            ultimo->prox = menor;
            ultimo = ultimo->prox;
        }
    }
    if (p == NULL){
        ultimo->prox = q;
    }
    else{
        ultimo->prox = p;
    }
    return r;
}

int main() {
    p = criar_no(0, criar_no(3, criar_no(5, criar_no(8, criar_no(10, NULL)))));
    q = criar_no(2, criar_no(7, criar_no(9, criar_no(11, NULL))));
    printa_lista (p, "Lista P");
    printa_lista (q, "Lista Q");

    NoLista * r = merge(p, q);

    printa_lista(r,"Lista mergeada");
}
