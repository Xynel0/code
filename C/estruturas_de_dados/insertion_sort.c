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
void insertion_sort (int * A, int n){  //recebe lista e tamanho
    int x, i;                          //x guardará o elemento em análise, i será o iterador reverso
    for(int j = 1; j < n; ++j){        //percorre a lista partindo do segundo elemento até o último
        x = A[j];                      //x recebe o elemento atual
        i = j -1;                      //i recebe o indice do item anterior
        while(i >= 0 && A[i] > x){     //passa pela lista de i até 0 ou para quando A[i]<=j fazendo...
            A[i +1] = A[i];                //copia o item atual no atual+1
            i = i -1;                      //itera de forma decrescente
        }
        A[i+1] = x;                    //achando um número menor que o x, copia x na posição seguinte a ele
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
