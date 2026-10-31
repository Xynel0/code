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
NoLista * r;





// -- escreva seu código abaixo, não altere esta linha



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
    if (p->valor <= q->valor){
        p->prox = merge(p->prox, q);
        return p;
    }
    q->prox = merge(p, q->prox);
    return q;
}

int main() {
    p = criar_no(0, criar_no(3, criar_no(5, criar_no(8, criar_no(10, NULL)))));
    q = criar_no(2, criar_no(7, criar_no(9, criar_no(11, NULL))));
    printa_lista (p, "Lista P");
    printa_lista (q, "Lista Q");

    r = merge(p, q);

    printa_lista(r,"Lista mergeada");
}
