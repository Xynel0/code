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




void printa_lista(NoLista * item){ //recebe uma lista encadeada e a imprime
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

int main() {
    p = criar_no(5, criar_no(8, criar_no(13, criar_no(2, NULL)))); //inicializa a lista
	  printa_lista(p);

    NoLista *q = p;        //criamos o ponteiro 'q', que irá passar pela lista original
	  p = NULL;            //fazemos o ponteiro 'p' apontar para nulo, "criando", assim, uma lista vazia
    while(q != NULL){      //enquanto 'q' não chegar ao final da lista, continuaremos a transferir os nós para a outra lista
		if (p == NULL){         //caso base: 'p' aponta para nulo, ou seja, lista vazia.
			p = q;              //fazemos 'p' apontar para onde 'q' estiver
			q = q->prox;        //daí, 'q' avança, enquanto 'p' se mantém no mesmo nó
			p->prox = NULL;     //o campo de 'p' que aponta para o próximo elemento da lista passa a apontar para nulo.
                                //daí, 'p' agora aponta para uma lista encadeada com um elemento, enquanto 'q' aponta para o que sobrou da lista original
		}
		else{                   //caso não-base, ou seja, lista nova já tem ao menos um item
			NoLista *r = q;     //criamos um ponteiro auxiliar 'r' que guarda o nó atualmente apontado por 'q'
			q = q->prox;        //avançamos 'q' como anteriormente, mantendo 'r' apontando para o mesmo nó
			r->prox = p;        //fazemos o 'prox' do nó apontado por 'r' apontar para a nova lista(que é para onde 'p' aponta)
			p = r;              //por fim, 'p' aponta para onde 'r' aponta, fazendo com que a lista apontada por 'p' comece no novo nó
		}
    }
	printa_lista(p);
}
