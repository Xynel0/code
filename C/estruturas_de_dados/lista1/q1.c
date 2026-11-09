#include <stdlib.h>
#include <stdio.h>

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

void soma_vetor (int A[], int B[], int C[], int n){
    int carry = 0;
    for (int i = n-1; i >= 0; --i){
        C[i+1] = (A[i]+B[i]+carry)%2;
        if (A[i]+B[i]+carry > 1){
            carry = 1;
        }
        else{
            carry = 0;
        }
    }
    C[0] = carry;
}

int main (){
    //recebe o tamanho da lista e cria uma lista com esse tamanho
    int n;
    recebe_int("Insira o tamanho das listas:\n", &n);
    int A[n];
    int B[n];
    int C[n+1];
    
    //recebe cada elemento da lista 1
    for(int i = 0; i < n; ++i){
        printf("Insira o bit %d do vetor 1:\n", i+1);
        recebe_int("", &A[i]);
    }
    printa_lista(A, n);

    //recebe cada elemento da lista 2
    for(int i = 0; i < n; ++i){
        printf("Insira o bit %d do vetor 2:\n", i+1);
        recebe_int("", &B[i]);
    }
    printa_lista(B, n);

    soma_vetor(A, B, C, n);
    printa_lista(C, n+1);
}
