#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};

int smimpar;

// -- escreva seu código abaixo dessa linha --- (e não altere esta linha)


int main() {
    int mimpar = -1;
  	smimpar = -1;
	for (int i = 0; i < N; ++i){
  		if (mimpar == -1){
	      	if (L[i] % 2 == 1){
  				mimpar = L[i];
            }
        }
      	else{
          	if (L[i] % 2 == 1){
              	if (L[i] < mimpar){
  					smimpar = mimpar;
              		mimpar = L[i];
                }
              	else if (L[i] < smimpar){
                  	smimpar = L[i];
                }
            }
        }
    }

}
