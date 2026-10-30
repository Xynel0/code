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

int k = 7;


// -- escreva seu código abaixo, não altere esta linha



void printa_lista(NoLista * item){
    while (item != NULL){
        printf("[%d]-> ", item-> valor);
        item = item-> prox;
    };
    printf("NULL\n");
}

int main() {
    NoLista * p = criar_no(7,criar_no(9,criar_no(4,criar_no(8,criar_no(2,(criar_no(10,criar_no(1,NULL)))))))); //inicializa a lista
    printa_lista(p); //imprime a lista antes do processo


    //cria ponteiros para apontarem para: o início de uma lista de maiores, o nó final de uma lista de menores ou iguais e o nó final de uma lista de maiores, respectivamente
    NoLista * maiores = NULL, * f_menorigual = NULL, * fmaiores = NULL;     //não criamos um nó para o começo da lista de menores ou iguais porque a saída pede que os menores ou iguais venham na frente,
                                                                            //então o ponteiro p pode guardar o início da lista de menores ou iguais
    NoLista * q = p;                //cria um ponteiro 'q' para percorrer a lista
    p = NULL;                       //faz p apontar para o nulo, "criando" uma lista vazia
    while (q != NULL){              //enquanto 'q' não acabar de percorrer a lista original...
        if(q->valor <= k){                   //se o valor do nó apontado por 'q' for menor ou igual, adicionamos na lista de menores ou iguais, ou seja, na lista apontada por 'p'
            if(p == NULL){                          //se a lista apontada por 'p' ainda estiver vazia
                p = q;                                  //'p' aponta para o nó que 'q' aponta
                f_menorigual = p;                       //o final dos menores ou iguais agora é 'p'
                q = q->prox;                            //avançamos 'q'
                f_menorigual->prox = NULL;              //fazemos o fim dos menores ou iguais apontar para nulo
            }
            else{                                   //se a lista dos menores ou iguais não está vazia
                f_menorigual->prox = q;                 //o 'prox' do nó final dos menores ou iguais passa a ser onde 'q' aponta
                f_menorigual = f_menorigual->prox;      //fazemos o nó final dos menores ou iguais agora ser o nó que adicionamos
                q = q->prox;                            //avançamos 'q'
                f_menorigual->prox = NULL;              //fazemos o 'prox' do fim dos menores ou iguais apontar para nulo
            }
        }
        else{                                   //se o valor do nó apontado por 'q' for maior
            if(maiores == NULL){                    //se os maiores estiverem vazios
                maiores = q;                            //'maiores' aponta para onde 'q' está
                fmaiores = maiores;                     //'fim dos maiores' passa a ser o unico nó dos maiores
                q = q->prox;                            //'q' aponta para o próximo da lista original
                fmaiores->prox = NULL;                  //'prox' de 'fim dos maiores' aponta para nulo
            }
            else{                                   //se os maiores não estiverem vazios
                fmaiores->prox = q;                     //'prox' do 'fim dos maiores' passa a ser onde 'q' aponta
                fmaiores = fmaiores->prox;              //avançamos o 'fim dos maiores' para o novo nó final
                q = q->prox;                            //avançamos 'q'
                fmaiores->prox = NULL;                  //'prox' do novo 'fim dos maiores' passa a ser nulo
            }
        }
    }
    //após acabarmos de destruir a lista original separando-a em duas (uma com maiores e outra com menores ou iguais)
    f_menorigual->prox = maiores; //'prox' do 'fim dos menores ou iguais' passa a apontar para a lista de maiores, juntando assim as duas listas
    
    printa_lista(p);//imprime a lista após o processo
}
