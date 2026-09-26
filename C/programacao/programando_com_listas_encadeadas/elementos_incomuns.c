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
int resp;




// -- escreva seu código abaixo, não altere esta linha



int main() {
    while (p != NULL || q != NULL) {
        if (p == NULL) {
            int valor = q->valor;
            while (q != NULL && q->valor == valor) {
                ++resp;
                q = q->prox;
            }
        }
        else if (q == NULL) {
            int valor = p->valor;
            while (p != NULL && p->valor == valor) {
               ++resp;
               p = p->prox;
            }
        }
        else if (p->valor < q->valor) {
            int valor = p->valor;
            while (p != NULL && p->valor == valor) {
                ++resp;
                p = p->prox;
            }
        }
        else if (q->valor < p->valor) {
            int valor = q->valor;
            while (q != NULL && q->valor == valor) {
                ++resp;
                q = q->prox;
            }
        }
        else {
            int valor = p->valor;
            while (p != NULL && p->valor == valor){
                p = p->prox;
            }
            while (q != NULL && q->valor == valor){
                q = q->prox;
            }
        }
    }
}
