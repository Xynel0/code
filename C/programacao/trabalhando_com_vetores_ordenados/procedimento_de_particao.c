#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {10,9,8,7,6,5,4,3,2,1};

int k = 6;

// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int main() {
    int balde, meio = 0;
    for(int i = 0; i < N; ++i){
        if (L[i] < k){
            balde = L[i];
            for(int j = i; j > meio; --j){
                L[j] = L[j-1];
            }
            L[meio] = balde;
            ++meio;
        }
    }

	for (int i = 0; i < N; ++i){
		printf("%d, ", L[i]);
	}
	printf("\n");
}
