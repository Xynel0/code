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



void printa_lista(NoLista * item){ //recebe um ponteiro paara uma lista encadeada e a imprime
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

int main() {
    NoLista * p = criar_no(7,criar_no(9,criar_no(4,criar_no(8,criar_no(2,(criar_no(10,criar_no(1,NULL)))))))); //inicializa a lista
    printa_lista(p); //imprime a lista antes do processo


    //cria ponteiros para apontarem para: o início de uma lista de ímpares, o nó final de uma lista de pares e o nó final de uma lista de impares, respectivamente
    NoLista * impares = NULL, * fpares = NULL, * fimpares = NULL; //não criamos um nó para o começo da lista de pares porque a saída pede que os pares venham na frente,
                                                                  //então o ponteiro p pode guardar o início da lista de pares
    NoLista * q = p;                //cria um ponteiro 'q' para percorrer a lista
    p = NULL;                       //faz p apontar para o nulo, "criando" uma lista vazia
    while (q != NULL){              //enquanto 'q' não acabar de percorrer a lista original...
        if(q->valor %2 == 0){           //se o valor do nó apontado por 'q' for par, adicionamos na lista de pares, ou seja, na lista apontada por 'p'
            if(p == NULL){                  //se a lista apontada por 'p' ainda estiver vazia
                p = q;                      //'p' aponta para o nó que 'q' aponta
                fpares = p;                 //o final dos pares agora é 'p'
                q = q->prox;                //avançamos 'q'
                fpares->prox = NULL;        //fazemos o fim dos pares apontar para nulo
            }
            else{                           //se a lista dos pares não está vazia
                fpares->prox = q;           //o 'prox' do nó final dos pares passa a ser onde 'q' aponta
                fpares = fpares->prox;      //fazemos o nó final dos pares agora ser o nó que adicionamos
                q = q->prox;                //avançamos 'q'
                fpares->prox = NULL;        //fazemos o 'prox' do fim dos pares apontar para nulo
            }
        }
        else{                           //se o valor do nó apontado por 'q' for ímpar
            if(impares == NULL){            //se os ímpares estiverem vazios
                impares = q;                    //'impares' aponta para onde 'q' está
                fimpares = impares;             //'fim dos impares' passa a ser o unico nó dos ímpares
                q = q->prox;                    //'q' aponta para o próximo da lista original
                fimpares->prox = NULL;          //'prox' de 'fim dos impares' aponta para nulo
            }
            else{                           //se os ímpares não estiverem vazios
                fimpares->prox = q;             //'prox' do 'fim dos impares' passa a ser onde 'q' aponta
                fimpares = fimpares->prox;      //avançamos o 'fim dos impares' para o novo nó final
                q = q->prox;                    //avançamos 'q'
                fimpares->prox = NULL;          //'prox' do novo 'fim dos impares' passa a ser nulo
            }
        }
    }
    //após acabarmos de destruir a lista original separando-a em duas (uma com ímpares e outra com pares)
    fpares->prox = impares; //'prox' do 'fim dos pares' passa a apontar para a lista de ímpares, juntando assim as duas listas
    
    printa_lista(p);//imprime a lista após o processo
}
