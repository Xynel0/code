#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////// FUNÇÕES AUXILIARES ///////////////////////////////////////////////////////

//recebe uma mensagem e um ponteiro para int, imprime a mensagem, recebe uma entrada e guarda na posição do ponteiro
void recebe_int(char msg[], int * elemento){
    printf("%s", msg);
    scanf("%d", elemento);
}

//recebe uma lista e seu tamanho e a imprime
void printa_lista(int * A, int n){
    printf("Vetor usado:\n[");
    for (int i = 0; i < n; ++i){
        if (i == n -1){
            printf("%d]\n\n", A[i]);
            return;
        }
        printf("%d, ", A[i]);
    }
}

//======================================================= ideia =======================================================
// A ideia da pilha é que o elemento a sair é sempre o último que entrou. Na implementação em um vetor, guardaremos o
// índice do ultimo elemento e trabalhamos em função dele. Sabemos que uma pilha está vazia quando seu topo se encontra
// na primeira posição do vetor. E sabemos que a pilha está cheia se o topo se encontra na última posição do vetor.


/////////////////////////////////////////////////////// PARTE CENTRAL ///////////////////////////////////////////////////////

// criamos a estrutura pilha
struct stack{
    int * vetor;        // ponteiro para o vetor onde a pilha será guardada
    int tam_max;        // índice máximo do vetor +1 (pois o vetor vai de 0 a tam_max)
    int top;            // índice da primeira posição livre da pilha
};

typedef struct stack stack;  // tornando possível chamar a struct apenas por queue

// verifica se a pilha está vazia
int empty_stack (stack * s){
    if (s->top == 0){
        return 1;
    }
    return 0;
}

//verifica se a pilha está cheia
int full_stack (stack * s){
    if (s->top == s->tam_max -1){
        return 1;
    }
    return 0;
}

//põe um número na pilha
void push (stack * s, int elemento){
    if (full_stack(s)){
        printf("ERRO: Stack Overflow!\n");
        return;
    }
    s->vetor[s->top] = elemento;
    ++s->top;
    return;
}

// retira um número da pilha
int * pop (stack * s){
    if (empty_stack(s)){
        printf("ERRO: Stack Underflow!\n");
        return NULL;
    }

    --s->top;
    int * ret = malloc(sizeof(int));
    * ret = s->vetor[s->top];
    s->vetor[s->top] = 0;
    return ret;
}

void print_stack(stack * s){
    printf("Pilha:\n[");
    for (int i = 0; i <= s->top -1; ++i){
        if (i == s->top -1){
            printf("%d", s->vetor[i]);
            break;
        }
        printf("%d, ", s->vetor[i]);
    }
    printf("]\n");
    return;
}

stack * create_stack (int tamanho_do_vetor){
    stack * s = malloc(sizeof(stack));
    s->tam_max = tamanho_do_vetor;
    s->top = 0;
    s->vetor = calloc(s->tam_max, sizeof(int));
    return s;
}


int main(){
    int tam_vetor = -1;
    recebe_int("OLÁ! Este programa mostra uma implementação de pilha em vetor.\nA cada passo, serão impressos tanto o vetor quanto a pilha para uma melhor visualização.\nPara iniciar informe o tamanho do vetor a ser criado para guardar a pilha.\nLembrando que se o vetor tem tamanho n, a fila terá no máximo n-1 elementos.\nApós isso, você poderá operar nesta pilha.\nINSIRA O TAMANHO DO VETOR(INT):\n", &tam_vetor);
    while (tam_vetor <= 1){
        recebe_int("Insira um valor maior que 1:\n", &tam_vetor);
    }
    stack * pilha = create_stack(tam_vetor);                                 //cria a estrutura pilha

    printa_lista(pilha->vetor, tam_vetor);
    print_stack(pilha);


    int option = -1;
    printf("Agora que temos a pilha criada... ");
        while (option != 0){
        recebe_int("Você pode\n1 - Ver apenas o vetor\n2 - Ver apenas a pilha\n3 - Ver se a pilha está vazia\n4 - Ver se a pilha está cheia\n5 - Adicionar um elemento\n6 - Remover um elemento\n0 - Apagar a pilha e sair\n\n======================================\nInsira sua escolha:\n", &option);
        if (option == 0){
            break;
        }
        if (option == 1){
            printa_lista(pilha->vetor, tam_vetor);
            printf("\n");
        }
        else if (option == 2){
            print_stack(pilha);
            printf("\n");
        }
        else if (option == 3){
            if (empty_stack(pilha)){
                printf("Pilha vazia\n\n");
                continue;
            }
            printf("Pilha não vazia\n\n");
        }
        else if (option == 4){
            if (full_stack(pilha)){
                printf("Pilha cheia\n\n");
                continue;
            }
            printf("Pilha não cheia\n\n");
        }
        else if (option == 5){
            int elemento;
            recebe_int("Insira o número que deseja adicionar à lista:\n", &elemento);
            push(pilha, elemento);
            printa_lista(pilha->vetor, tam_vetor);
            print_stack(pilha);
            printf("\n");
        }
        else if (option == 6){
            int * ret = pop(pilha);
            if (ret == NULL){
                printa_lista(pilha->vetor, tam_vetor);
                print_stack(pilha);
                printf("\n");
                continue;
            }
            printf("O elemento retirado foi: %d\n", *ret);
            printa_lista(pilha->vetor, tam_vetor);
            print_stack(pilha);
            printf("\n");
        }
        else{
            printf("ERRO: OPÇÃO INVÁLIDA!\n\n");
        }
    }

    free(pilha->vetor);                                          // libera o espaço do vetor usado pela pilha
    free(pilha);                                                 // libera o espaço usado pelo resto da pilha
    printf("Tenha um bom dia (:\n");
}
