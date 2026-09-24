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
    NoLista * a = p,* b = p;
    resp = p->valor;
    int maiorseq = 0;
    while (a != NULL){
        b = a;
        int seq = 0;
        while (b != NULL){
            if(a->valor == b->valor){
                ++seq;
                if(seq > maiorseq){
                    maiorseq = seq;
                    resp = a->valor;
                }
            }
            b = b->prox;
        }
        a = a->prox;
    }
}
