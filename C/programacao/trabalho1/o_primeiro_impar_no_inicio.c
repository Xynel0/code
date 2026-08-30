#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};


// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int main() {
	for (int i = 0; i < N; ++i){
      	if (L[i] % 2 == 1){
          	int fimpar = L[i];
          	for (int j = i; j > 0; --j){
              	L[j] = L[j-1];
            }
          	L[0] = fimpar;
          	break;
        }
    }

}
