// inclua as bibliotecas e definas as variáveis globais de entrada e saída do modelo
#include <stdlib.h>
#include <stdio.h>

#define N 10

int L[N] = {1,2,3,4,5,6,7,8,9,10};

int mm;

// -- escreva seu código abaixo, não altere esta linha



int main() {
	float media = 0;
  	mm = 0;
	for (int i = 0; i < N; ++i){
      	media = media + L[i];
    }
  	media = (float)media / N;
  	for (int i = 0; i < N; ++i){
      	if (L[i] > media){
          	++mm;
        }
    }
}
