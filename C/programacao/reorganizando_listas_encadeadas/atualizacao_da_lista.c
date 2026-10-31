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




// -- escreva seu código abaixo, não altere esta linha



void printa_lista(NoLista * item){
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

int main() {
    NoLista * p = criar_no(-1, criar_no(2, criar_no(5, criar_no(5, criar_no(8, criar_no(8, criar_no(8, criar_no(9, criar_no(9, NULL)))))))));
    printa_lista(p);

    NoLista * q = p, * anterior = NULL;
    NoLista * dobro = NULL;
    while(q != NULL){
        if (q->valor %2 == 1 || q->valor %2 == -1){
            dobro = criar_no(q->valor *2, NULL);
            if (q == p){
                p = p->prox;
            }
            else{
                anterior->prox = q->prox;
            }
            break;
        }
        anterior = q;
        q = q->prox;
    }
    if(q == NULL){
        return 0;
    }
    q = p;
    anterior = NULL;
    while(q != NULL){
        if (q->valor > dobro->valor){
            if (q == p){
                dobro->prox = p;
                p = dobro;
            }
            else{
                dobro->prox = q;
                anterior->prox = dobro;
            }
            printa_lista(p);
            return 0;
        }
        anterior = q;
        q = q->prox;
    }
    dobro->prox = NULL;
    anterior->prox = dobro;
    printa_lista(p);
}
