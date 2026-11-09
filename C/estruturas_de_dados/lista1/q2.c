#include <stdio.h>
#include <stdlib.h>

void recebe_int(char msg[], int * elemento){ //recebe uma mensagem e um ponteiro, imprime a mensagem, recebe uma entrada e guarda na posição do ponteiro
    printf("%s", msg);
    scanf("%d", elemento);
}

void printa_lista(int * A, int n){ //recebe uma lista e seu tamanho e a imprime
    printf("[");
    for (int i = 0; i < n; ++i){
        if (i == n -1){
            printf("%d]\n", A[i]);
            return;
        }
        printf("%d, ", A[i]);
    }
}


//============================================= INSERTION SORT =============================================
// invariante: A[0,..., j-1] está ordenada
void insertion_sort (int * A, int n){
    for (int i = 0; i < n-1; ++i){
        int menor = A[i];
        int i_menor = i;
        for (int j = i; j < n; ++j){
            if (A[j] < menor){
                menor = A[j];
                i_menor = j;
            }
        }
        A[i_menor] = A[i];
        A[i] = menor;
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


    insertion_sort(L, n); //ordena a lista
    printa_lista(L, n);   //imprime a lista ordenada
}
