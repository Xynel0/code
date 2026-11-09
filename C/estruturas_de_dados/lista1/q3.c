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

/////////////////////////////////////////////////////// PARTE CENTRAL ///////////////////////////////////////////////////////

// criamos a estrutura pilha
struct stack{
    int top;            // índice da primeira posição livre da pilha
    int n;
};

typedef struct stack stack;  // tornando possível chamar a struct apenas por queue

struct double_stack {
    int * A;
    int tam_max;
    stack * s1;
    stack * s2;
};

typedef struct double_stack ds;

// verifica se a pilha está vazia
int empty_stack (ds * d_stack, stack * s){
    if (s->n == 0){
        if (s->top == 0){
            return 1;
        }
        return 0;
    }
    else if (s->n == 1){
        if (s->top == d_stack->tam_max -1){
            return 1;
        }
        return 0;
    }
    printf("ERRO: pilha não identificada\n");
    return -1;
}

//verifica se a pilha está cheia
int full_stack (ds * d_stack){
    if (d_stack->s1->top == d_stack->s2->top){
        return 1;
    }
    return 0;
}

//põe um número na pilha
void push (ds * d_stack, stack * s, int elemento){
    if (full_stack(d_stack)){
        printf("ERRO: Stack Overflow!\n");
        return;
    }
    if (s->n == 0){
        d_stack->A[s->top] = elemento;
        ++s->top;
        return;
    }
    else if (s->n == 1){
        d_stack->A[s->top] = elemento;
        --s->top;
    }
}

// retira um número da pilha
int * pop (ds * d_stack, stack * s){
    if (empty_stack(d_stack, s)){
        printf("ERRO: Stack Underflow!\n");
        return NULL;
    }
    int * ret = malloc(sizeof(int));

    if (s->n == 0){
        --s->top;
        * ret = d_stack->A[s->top];
        d_stack->A[s->top] = 0;
    }
    else if (s->n == 1){
        ++s->top;
        * ret = d_stack->A[s->top];
        d_stack->A[s->top] = 0;
    }
    return ret;
}

void print_stack(ds * d_stack, stack * s){
    if (s->n == 0){
        printf("Pilha esq:\n[");
        for (int i = 0; i <= s->top -1; ++i){
            if (i == s->top -1){
                printf("%d", d_stack->A[i]);
                break;
            }
            printf("%d, ", d_stack->A[i]);
        }
        printf("]\n");
    }
    else if (s->n == 1){
        printf("Pilha dir:\n[");
        for (int i = d_stack->tam_max -1; i > s->top; --i){
            if (i == s->top +1){
                printf("%d", d_stack->A[i]);
                break;
            }
            printf("%d, ", d_stack->A[i]);
        }
        printf("]\n");
    }
    return;
}

stack * create_stack (ds * d_stack, int n_stack){
    stack * s = malloc(sizeof(stack));
    if (n_stack== 0){
        s->top = 0;
        s->n = 0;
        return s;
    }
    s->top = d_stack->tam_max -1;
    s->n = 1;
    return s;
}

ds * create_ds (int tamanho_do_vetor){
    ds * d_stack = malloc(sizeof(ds));
    d_stack->tam_max = tamanho_do_vetor;
    d_stack->A = calloc(tamanho_do_vetor, sizeof(int));
    d_stack->s1 = create_stack(d_stack, 0);
    d_stack->s2 = create_stack(d_stack, 1);
    return d_stack;
}


int main(){
    int tam_vetor = -1;
    recebe_int("OLÁ! Este programa mostra uma implementação de pilha em vetor.\nA cada passo, serão impressos tanto o vetor quanto a pilha para uma melhor visualização.\nPara iniciar informe o tamanho do vetor a ser criado para guardar a pilha.\nLembrando que se o vetor tem tamanho n, a fila terá no máximo n-1 elementos.\nApós isso, você poderá operar nesta pilha.\nINSIRA O TAMANHO DO VETOR(INT):\n", &tam_vetor);
    while (tam_vetor <= 1){
        recebe_int("Insira um valor maior que 1:\n", &tam_vetor);
    }
    ds * pilha_d = create_ds(tam_vetor);                                 //cria a estrutura pilha

    printa_lista(pilha_d->A, tam_vetor);
    print_stack(pilha_d, pilha_d->s1);
    print_stack(pilha_d, pilha_d->s2);

    int option = -1;
    printf("Agora que temos a pilha criada... ");
        while (option != 0){
        recebe_int("Você pode\n1 - Ver apenas o vetor\n2 - Ver apenas as pilhas\n3 - Ver se a pilha está vazia\n4 - Ver se a pilha está cheia\n5 - Adicionar um elemento\n6 - Remover um elemento\n0 - Apagar a pilha e sair\n\n======================================\nInsira sua escolha:\n", &option);
        if (option == 0){
            break;
        }
        if (option == 1){
            printa_lista(pilha_d->A, tam_vetor);
            printf("\n");
        }
        else if (option == 2){
            print_stack(pilha_d, pilha_d->s1);
            print_stack(pilha_d, pilha_d->s2);
            printf("\n");
        }
        else if (option == 3){
            if (empty_stack(pilha_d, pilha_d->s1)){
                printf("Pilha esq vazia\n\n");
            }
            else{
                printf("Pilha esq não vazia\n\n");
            }
            if (empty_stack(pilha_d, pilha_d->s2)){
                printf("Pilha dir vazia\n\n");
            }
            else{
                printf("Pilha dir não vazia\n\n");
            }
        }
        else if (option == 4){
            if (full_stack(pilha_d)){
                printf("Pilhas cheias\n\n");
                continue;
            }
            printf("Pilhas não cheias\n\n");
        }
        else if (option == 5){
            int elemento;
            int nfila;
            recebe_int("1 - adicionar a fila esquerda\n2 - adicionar a fila direita\ninsira sua opção:\n", &nfila);
            if (nfila == 1){
                recebe_int("Insira o número que deseja adicionar à lista:\n", &elemento);
                push(pilha_d, pilha_d->s1, elemento);
            }
            else if (nfila == 2){
                recebe_int("Insira o número que deseja adicionar à lista:\n", &elemento);
                push(pilha_d, pilha_d->s2, elemento);
            }
            else{
                printf("ERRO: pilha não identificada\n");
            }
            
            print_stack(pilha_d, pilha_d->s1);
            print_stack(pilha_d, pilha_d->s2);
            printf("\n");
        }
        else if (option == 6){
            int nfila;
            int * ret;
            recebe_int("1 - remover da fila esquerda\n2 - remover da fila direita\ninsira sua opção:\n", &nfila);
            if (nfila == 1){
                ret = pop(pilha_d, pilha_d->s1);
            }
            else if (nfila == 2){
                ret = pop(pilha_d, pilha_d->s2);
            }
            else{
                printf("ERRO: pilha não identificada\n");
            }
            if (ret == NULL){
                printa_lista(pilha_d->A, tam_vetor);
                print_stack(pilha_d, pilha_d->s1);
                print_stack(pilha_d, pilha_d->s2);
                printf("\n");
                continue;
            }
            printf("O elemento retirado foi: %d\n", *ret);
            printa_lista(pilha_d->A, tam_vetor);
            print_stack(pilha_d, pilha_d->s1);
            print_stack(pilha_d, pilha_d->s2);
            printf("\n");
        }
        else{
            printf("ERRO: OPÇÃO INVÁLIDA!\n\n");
        }
    }

    free(pilha_d->s1);                                          // libera o espaço do vetor usado pela pilha
    free(pilha_d->s2);
    free(pilha_d->A);
    free(pilha_d);                                                 // libera o espaço usado pelo resto da pilha
    printf("Tenha um bom dia (:\n");
}
