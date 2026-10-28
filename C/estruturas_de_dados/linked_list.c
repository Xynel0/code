//Solicita o tamanho de uma lista encadeada e cria a lista com os elementos fornecidos pelo usuário. Após isso, imprime e mostra a lista.
//Este arquivo tenta explicar boa parte das coisas. Funções daqui serão reaproveitadas para outros arquivos de lista encadeada, porém sem a mesma explicação detalhada.

#include <stdlib.h>
#include <stdio.h>

void recebe_int(char msg[], int * elemento){ //recebe uma mensagem e um ponteiro, imprime a mensagem, recebe uma entrada e guarda na posição do ponteiro
    printf("%s", msg);
    scanf("%d", elemento);
}


//================= Início do processo de criar a linked-list =================

// cria uma struct chamada no (nó). Cada nó terá um campo "valor" de tipo int,
// que guardará o valor, e um campo "prox" do tipo ponteiro para uma stuct no,
// que apontará para o local na memória que guardar o próximo elemento

struct no{
    int valor;
    struct no *prox;
};


// para evitarmos digitar o "struct no [nome_do_no]" sempre que declararmos 
// alguma variável nó, usamos o typedef para podermos chamar os nós apenas de no. 
typedef struct no no;


// essa função teve que vir pra cá porque recebe um nó.
// por isso tem que estar após a criação do tipo nó
void printa_lista(no * item){ //recebe uma lista e a imprime
    while (item != NULL){                   // enquanto o nó observado não for nulo...
        printf("[%d]-> ", item-> valor);    // imprime o valor do nó com um fru-fru
        item = item-> prox;                 // faz "item" apontar para o nó seguinte
    };                                      // eventualmente o próximo de algum nó será nulo. isso encerrará o while
    printf("NULL\n");                       // pra ficar bonito, imprime null e uma quebra de linha.
}



// ============================= função que cria um nó (retorna um ponteiro para o nó recém criado) =============================
// recebe o valor a ser guardado no nó e um ponteiro para algum local
// (idealmente o "local" será um outro nó, mas pode ser que aponte para null, a depender do caso)
no * cria_no(int valor, no * proximo){
    no * p = malloc(sizeof(no));    // cria um ponteiro "p" para uma "variável" do tipo nó.
                                    // A função malloc aloca na memória um espaço do tamanho de um nó
                                    // e retorna o endereço de memória desse espaço. 'p' aponta para esse endereço.
    p->valor = valor;               // preenche o campo valor com o valor recebido
    p->prox = proximo;              // preenche o campo prox com o ponteiro recebido
    return p;                       // retorna o endereço de memória guardado em 'p', isto é, o endereço do nó criado
}

int main(){

    //recebe o tamanho da lista e cria uma lista com esse tamanho
    int n;
    recebe_int("Insira o tamanho da lista:\n", &n);
    
    no * i_lista;                                           // cria um ponteiro "i-lista" para um nó. Guardará o início da lista.
    no * f_lista;                                           // cria um ponteiro "f-lista" para um nó. Guardará o fim da lista.
    for(int i = 0; i < n; ++i){                             // itera n vezes, criando e encadeando os nós
        int valor_do_no;                                    // variável para receber o valor a ser posto no nó

        printf("Insira o elemento de número %d:\n", i+1);   // recebe o valor e guarda-o na variável acima
        recebe_int("", &valor_do_no);                       //

        no * p = cria_no(valor_do_no, NULL);                // cria um ponteiro para um nó. aponta para o endereço retornado pela função criar nó,
                                                            // que cria um nó com o valor passado e cujo "prox" aponta para nulo.


        if(i_lista == NULL){                                // se o ponteiro que guarda o inicio ainda não tiver sido inicializado, ou seja, se a lista ainda estiver vazia,
            i_lista = p;                                    // faz o ponteiro do inicio da lista apontar para o nó criado
            f_lista = p;                                    // faz o ponteiro do fim da lista apontar para o nó criado
        }
        else{                                               // se há algum início,
            f_lista->prox = p;                              // faz o "prox" do nó final apontar para o nó criado
            f_lista = f_lista->prox;                        // atualiza o ponteiro do nó final para que aponte para o novo nó final.
        }
    }

    printa_lista(i_lista);   //imprime a lista ordenada
}
