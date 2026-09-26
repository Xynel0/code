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

/*
a inicialização será feita no sistema de tarefas
p = criar_no(5, criar_no(8, criar_no(13, criar_no(2, NULL))));
*/


// -- escreva seu código abaixo, não altere esta linha



int main() {
    q = NULL;
    NoLista * anterior = p;
    NoLista * atual = p->prox;
    while(atual != NULL){
        if (atual->valor < anterior->valor){
            if (q == NULL){
                q = criar_no(atual->valor, NULL);
            }
            else{
                NoLista * pointer = q;
                while(pointer->prox != NULL){
                    pointer = pointer->prox;
                }
                pointer->prox = criar_no(atual->valor, NULL);
            }
        }
        anterior = anterior->prox;
        atual = atual->prox;
    }
}
