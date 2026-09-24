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



int main() {
    NoLista * q = p;
    resp = 0;
    while(q != NULL){
        if (q->valor %2 == 1){
            if(resp == 0){
                resp = q->valor;
            }
            else if(q->valor < resp){
                resp = q->valor;
            }
        }
        q = q->prox;
    }
    printf("%d\n", resp);
}
