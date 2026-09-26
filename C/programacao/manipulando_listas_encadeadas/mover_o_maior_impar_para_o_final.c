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



int main() {
    NoLista * pointer = p, * maior_impar = NULL, * ant_maior_impar = NULL, * ant_pointer = NULL;
    while (pointer != NULL){
        if(pointer->valor %2 == 1){
            if(maior_impar == NULL){
                maior_impar = pointer;
                ant_maior_impar = ant_pointer;
            }
            else if(pointer->valor > maior_impar->valor){
                maior_impar = pointer;
                ant_maior_impar = ant_pointer;
            }
        }

        ant_pointer = pointer;
        pointer = pointer->prox;
    }
    if (maior_impar != NULL){
        if(ant_maior_impar == NULL){
            p = maior_impar->prox;
            maior_impar->prox = NULL;
            ant_pointer->prox = maior_impar;
        }
        else{
            ant_maior_impar->prox = maior_impar->prox;
            maior_impar->prox = NULL;
            ant_pointer->prox = maior_impar;
        }
    }
}
