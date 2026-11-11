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

int verifica_ordenacao(NoLista * p, int ant){
    if (p == NULL){
        return 1;
    }
    if (ant <= p->valor){
        return verifica_ordenacao(p->prox, p->valor);
    }
    return 0;
}

int main() {
    printa_lista(p);

    if(p == NULL || p->prox == NULL){
        resp = 1;
        return 0;
    }
    resp = verifica_ordenacao(p->prox, p->valor);

    printf("%d\n", resp);
}
