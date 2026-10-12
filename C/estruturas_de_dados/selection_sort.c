#include <stdio.h>
#include <stdlib.h>

void recebe_int(char msg[], int * elemento){ //recebe uma mensagem e um ponteiro, imprime a mensagem, recebe uma entrada e guarda na posição do ponteiro
    printf("%s", msg);
    scanf("%d", elemento);
}

void printa_lista(int * A, int n){ //recebe uma lista e seu tamanho e a imprime
    if (n == 0){
        return;
    }
    printf("[");
    for (int i = 0; i < n; ++i){
        if (i == n -1){
            printf("%d]\n", A[i]);
            return;
        }
        printf("%d, ", A[i]);
    }
}


//============================================= SELEECTION SORT =============================================
// invariante: A[0,..., i-1] está ordenada com os menores i elementos de A
void selection_sort (int * A, int n){           //  Entradas: lista e tamanho
    for(int i = 0; i < n; ++i){                 //  lê item por item da lista
        int menor = A[i];                       ////
        int indice_menor = i;                   ////
        for(int j = i + 1; j < n; ++j){         ////
            if (A[j] < menor){                  ////  procura o menor elemento em A[i,...,n]
                menor = A[j];                   ////
                indice_menor = j;               ////
            }                                   ////
        }                                       ////
        A[indice_menor] = A[i];                 //  troca o menor elemento obtido
        A[i] = menor;                           //  por A[i]
    }
}



int main(){

    //recebe o tamanho da lista e cria uma lista com esse tamanho
    int n;
    recebe_int("Insira o tamanho da lista:\n", &n);
    int L[n];
    
    //recebe cada elemento da lista
    for(int i = 0; i < n; ++i){
        printf("Insira o elemento de número %d:\n", i+1);
        recebe_int("", &L[i]);
    }


    selection_sort(L, n); //ordena a lista
    printa_lista(L, n);   //imprime a lista ordenada
}
