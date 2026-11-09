#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no * prox;
};

typedef struct no no;

struct pilha{
    no * top;
};

typedef struct pilha pilha;

int empty_stack (pilha * p){
    if (p->top == NULL){
        return 1;
    }
    return 0;
}

void push (pilha * p, no * x){
    x->prox = p->top;
    p->top = x;
}

int pop (pilha * p){
    if (empty_stack(p)){
        printf("ERRO: stack underflow!\n");
        return 0;
    }
    int x = p->top->valor;
    p->top = p->top->prox;
    return x;
}

no * create_node (int valor, no * prox){
    no * node = malloc(sizeof(no));
    node->prox = prox;
    node->valor = valor;
    return node;
}

pilha * create_stack (){
    pilha * p = malloc(sizeof(pilha));
    p->top = NULL;
    return p;
}
