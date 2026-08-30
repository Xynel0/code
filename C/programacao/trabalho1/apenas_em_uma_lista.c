#include <stdlib.h>
#include <stdio.h>

#define N 10

int U[N] = {1,2,3,4,5,6,7,8,9,10};
int V[N] = {4,5,6,7,8,9,10,1,2,3};

int resp;


// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int unicos_por_lista(int L[], int M[]){
  	int counter = 0;
	for (int i = 0; i < N; ++i){
      	int unico = 1;
      	for (int j = 0; j < N; ++j){
          	if (L[i] == M[j]){
              	unico = 0;
            }
        }
      	if (unico == 1){
          ++counter;
        }
    }
  	return counter;
}

int main (){
  	resp = unicos_por_lista (U, V);
    resp = resp + unicos_por_lista (V, U);
}
