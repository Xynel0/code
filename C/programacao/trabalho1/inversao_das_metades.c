#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};

// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int main() {
	int baldin;
  	for (int i = 0; i < N/2; ++i){
      	baldin = L[i];
      	L[i] = L[i + N/2];
      	L[i + N/2] = baldin;
    }
}
