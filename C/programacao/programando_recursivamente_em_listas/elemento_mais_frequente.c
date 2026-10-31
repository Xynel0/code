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

int elemento_frequente(NoLista * p, int maxpast, int maxelem){
    int n = p->valor;
    int max = 0;
    while (p != NULL && p->valor == n){
        ++max;
        if (max > maxpast){
            maxpast = max;
            maxelem = p->valor;
        }
        p = p->prox;
    }
    if (p != NULL){
        maxelem = elemento_frequente(p, maxpast, maxelem);
    }
    return maxelem;
}
int main() {
    p = criar_no(2, criar_no(5,criar_no(5, criar_no(8, criar_no(8, criar_no(8, criar_no(9, criar_no(9, NULL)))))))); //inicializa lista
    printa_lista(p);
    resp = elemento_frequente(p, 0, -1);
    printf("%d\n", resp);
}
