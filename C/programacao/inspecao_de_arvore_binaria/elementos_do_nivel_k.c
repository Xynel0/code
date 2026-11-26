// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct NoArv{
	int valor;
	struct NoArv * esq;
	struct NoArv * dir;
} NoArv;

typedef struct NoLista{
	int valor;
	struct NoLista * prox;
} NoLista;

NoLista * criar_no_lista(int valor, NoLista * prox){
	NoLista * no = malloc(sizeof(NoLista));
	no->valor = valor;
	no->prox = prox;
	return no;
}

int k = 2;

NoArv * p;

NoLista * q;



// -- escreva seu código abaixo, não altere esta linha




NoLista * last;
void encadeia_nivel(NoArv * x, int nivel_atual){
    if (x == NULL){
        return;
    }
    encadeia_nivel(x->esq, nivel_atual+1);
    if (nivel_atual == k){
        if (q == NULL){
            q = criar_no_lista(x->valor, NULL);
            last = q;
        }
        else{
            last->prox = criar_no_lista(x->valor, NULL);
            last = last->prox;
        }
    }
    encadeia_nivel(x->dir, nivel_atual+1);
}
int main() {
    q = NULL;
    last = q;
    encadeia_nivel(p, 1);


  
}
