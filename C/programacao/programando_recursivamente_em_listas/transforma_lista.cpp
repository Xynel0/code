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



void printa_lista(NoLista * item){ //recebe um ponteiro para uma lista e a imprime
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

//NOTE QUE ESTA SOLUÇÃO NÃO É RECURSIVA, apesar de resolver o problema.

int main() {
    printa_lista(p); //imprime a lista antes do procedimento

    NoLista *last = p, *atual = p;                                                       	// cria ponteiros para percorrerem a lista, guardando as posições de dois elementos por vez
    if (p == NULL || p->prox == NULL){                                                      //se p for nulo ou tiver só um elemento, a operação não faz sentido
        printf("Lista vazia ou com somente um nó. Impossível completar a operação.\n");
        return 0;
    }
    else{                                                                                   //se a lista tem dois ou mais nós, podemos prosseguir
        atual = p->prox;                                                // 'atual' irá percorrer a lista como ponteiro principal até acabá-la. pelo if acima, é garantido neste ponto que há dois ou mais nós
        while (atual != NULL){                                          
            last->prox = criar_no(last->valor +atual->valor, atual);    // faz o 'prox' do nó anterior a 'atual' apontar para um novo nó, cujo valor é a soma dos dois nós e cujo 'prox' é o nó 'atual'
            last = atual;                                               // avançamos o last para assumir a posição de p
            atual = atual->prox;                                        // avançamos p e deixamos o procedimento se repetir até p chegar a nulo
        }
    }
    printa_lista(p); //imprime a lista depois do procedimento
}
