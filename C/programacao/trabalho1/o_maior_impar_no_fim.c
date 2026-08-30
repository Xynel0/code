#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};


// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int main() {
  	int maiorimpar = -1;
  	int indice;
  	for (int i = 0; i < N; ++i){
      	if (L[i] % 2 == 1){
          	if (maiorimpar == -1){
              	maiorimpar = L[i];
              	indice = i;
            }
        	else if (L[i] > maiorimpar){
              maiorimpar = L[i];
              indice = i;
            }
        }
    }
  	if (maiorimpar != -1){
  		for (int i = indice; i < N-1; ++i){
      		L[i] = L[i+1];
    	}
  		L[N-1] = maiorimpar;
    }
}
