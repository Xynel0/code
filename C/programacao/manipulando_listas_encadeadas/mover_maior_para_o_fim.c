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



int main() {
    NoLista * pointer = p, * antmaior = NULL, * maior = p, * antpointer = NULL;
    while(pointer != NULL){
        if (pointer->valor > maior->valor){
            maior = pointer;
            antmaior = antpointer;
        }
        antpointer = pointer;
        pointer = pointer->prox;
    }
    if (antmaior == NULL){
        p = p->prox;
        antpointer->prox = maior;
        maior->prox = NULL;
    }
    else{
        antmaior->prox = maior->prox;
        maior->prox = NULL;
        antpointer->prox = maior;
    }
}
