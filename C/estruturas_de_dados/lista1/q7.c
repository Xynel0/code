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


void printa_lista(NoLista * item){
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

NoLista * inverter_lista(NoLista * p){
    NoLista * x = NULL;
    NoLista * y = NULL;
    while (p != NULL){
        y = p;
        p = p->prox;
        y->prox = x;
        x = y;
    }
    return x;
}

int main() {
    p = criar_no(5, criar_no(8, criar_no(13, criar_no(2, NULL)))); //inicializa a lista
	printa_lista(p);
    p = inverter_lista(p);
	printa_lista(p);
}
