// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define N 10

int L[N] = {3,8,12,15,20,28,31,43,48,51};


// -- escreva seu código abaixo, não altere esta linha



int main() {
	int maior, i;
    for (int k = N-1; k >= 0; --k){
        if(L[k]%2 == 0){
            maior = L[k]/2;
            i = k;
            break;
        }
    }
  	int x = 1;
  	while (x == 1){
      	if (i == 0){
          	L[i] = maior;
            break;
        }
      	else if (L[i-1] > maior){
          	L[i] = L[i-1];
        }
      	else{
          	L[i] = maior;
            break;
        }
      	--i;
    }
}
