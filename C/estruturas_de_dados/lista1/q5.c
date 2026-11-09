#include <stdlib.h>
#include <stdio.h>

struct no{
    int valor;
    struct no * prox;
};
typedef struct no no;

struct queue{
    no * first;
    no * last;
};

typedef struct queue queue;

int empty_queue(queue * f){
    if (f->first == NULL){
        return 1;
    }
    return 0;
}

void enqueue (queue * f, no * x){
    if (empty_queue(f)){
        f->first = f->last = x;
        x->prox = NULL;
    }
    else{
        f->last->prox = x;
        x->prox = NULL;
        f->last = f->last->prox;
    }
}

int * dequeue (queue * f){
    if (empty_queue(f)){
        printf("ERRO: queue underflow!\n");
        return NULL;
    }
    if (f->first == f->last){
        f->last = NULL;
    }
    int * x = malloc(sizeof(int));
    *x = f->first->valor;
    f->first = f->first->prox;
    return x;
}

no * create_node(int valor, no * prox){
    no * node = malloc(sizeof(no));
    node->prox = prox;
    node->valor = valor;
    return node;
}

queue * create_queue(){
    queue * f = malloc(sizeof(queue));
    f->first = NULL;
    f->last = NULL;
    return f;
}
