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

NoLista * remove_copias(NoLista * p){
    if (p == NULL || p->prox == NULL){
        return p;
    }
    NoLista * no_pra_manter = p;
    p = p->prox;
    while (p != NULL && p->valor == no_pra_manter->valor){
        p = p->prox;
    }
    no_pra_manter->prox = remove_copias(p);
    return no_pra_manter;
}

int main() {
    printa_lista(p);

    remove_copias(p);

    printa_lista(p);
}
