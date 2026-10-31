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

/*
a inicialização será feita no sistema de tarefas
p = criar_no(5, criar_no(8, criar_no(13, criar_no(2, NULL))));
*/


// -- escreva seu código abaixo, não altere esta linha



void printa_lista(NoLista * item){ //recebe um ponteiro para uma lista e a imprime
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

int impares_em_impares(NoLista *p){
    if (p->valor %2 != 0){
        if (p->prox != NULL && p->prox->prox != NULL){
            return 1+ impares_em_impares(p->prox->prox);
        }
        return 1;
    }
    if (p->prox != NULL && p->prox->prox != NULL){
        return impares_em_impares(p->prox->prox);
    }
    return 0;
}

int main() {
    p = criar_no(5, criar_no(8, criar_no(13, criar_no(2, NULL))));
    printa_lista(p);

    if(p == NULL){
        resp = 0;
        return 0;
    }

    resp = impares_em_impares(p);

    printf("%d\n", resp);
}
