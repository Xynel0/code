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


int resp;



// -- escreva seu código abaixo, não altere esta linha



void printa_lista(NoLista * item){ //recebe um ponteiro para uma lista e a imprime
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

int trechos(NoLista * p, int last_value){
    if (p == NULL){
        return 0;
    }
    if (last_value <= p->valor){
        return trechos(p->prox, p->valor);
    }
    return 1 +trechos(p->prox, p->valor);
}

int main() {
    p = criar_no(7, criar_no(6, criar_no(5, criar_no(4, criar_no(3, criar_no(2, criar_no(1, criar_no(0, NULL))))))));
    printa_lista(p);
    if (p == NULL){
        resp = 0;
        printf("%d\n", resp);
        return 0;
    }
    if (p->prox == NULL){
        resp = 1;
        printf("%d\n", resp);
        return 0;
    }
    resp = trechos (p->prox, p->valor) + 1;
    printf("%d\n", resp);
}
