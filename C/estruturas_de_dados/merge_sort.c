#include <stdio.h>
#include <stdlib.h>


// ordem recomendada: entenda o merge. daí, assuma que ele ordena quaisquer duas listas ordenadas em uma única lista. então passe ao merge_sort.

//======

void recebe_int(char msg[], int * elemento){ //recebe uma mensagem e um ponteiro, imprime a mensagem, recebe uma entrada e guarda na posição do ponteiro
    printf("%s", msg);
    scanf("%d", elemento);
}

void printa_lista(int * A, int n){ //recebe uma lista e seu tamanho e a imprime
    if (n == 0){
        return;
    }
    printf("[");
    for (int i = 0; i < n; ++i){
        if (i == n -1){
            printf("%d]\n", A[i]);
            return;
        }
        printf("%d, ", A[i]);
    }
}

//======

//======================================================================================== MERGE ========================================================================================
void merge (int * A, int p, int q, int r){  //entrada: vetor A tal que A[p,...,q] e A[q+1,...,r] estão ordenados  (chamaremos A[p,...,r] de A')
    int n1 = q - p + 1;                     //quantidade de elementos entre p e q, incluindo-os. (Será o tamanho do vetor L)
    int n2 = r - q;                         //quantidade de elementos entre q+1 e r, incluindo-os. (Será o tamanho do vetor R)
                                            //
                                            //    P           q                       r
                                            //  [  ][  ][  ][  ][  ][  ][  ][  ][  ][  ]
                                            //   8   9   10  11  12  13  14  15  16  17
                                            //
                                            //   q-p +1 = 11-8 +1 = 4 posições    |    r - q = 17-11 = 6 posições
                                            //
    int L[n1 +1], R[n2 +1];                 //criamos dois vetores para guardar os elementos de A' separadamente. 
                                            //    A posição extra será usada para guardar um valor "infinito".
                                            //    usaremos os "for" a seguir tanto para preencher os vetores quanto para determinar o "infinito"
    int maior_de_todos = A[p];              //cria uma variável para o maior elemento das duas sublistas.

    for (int i = 0; i < n1; ++i){
        if(A[p+i] > maior_de_todos){        //vai trocando o maior de todos sempre que acha alguém maior que ele (o p+i é porque o início das listas não necessariamente é o início de A)
            maior_de_todos = A[p+i];
        }
        L[i] = A[p +i];                     //preenche o vetor L com o subvetor ordenado de A'
    }

    for (int i = 0; i < n2; ++i){
        if(A[q+1 +i] > maior_de_todos){     //continua trocando o maior, passando pela segunda sublista
            maior_de_todos = A[q+1 +i];
        }
        R[i] = A[q+1 +i];                   //preenche o vetor R com o segundo subvetor ordenado de A'
    }

    L[n1] = maior_de_todos +1;              //as ultimas posições dos dois vetores guardarão um número maior que qualquer outro da lista (o "infinito").
    R[n2] = maior_de_todos +1;              // lembrando que de 0 a n1 tem-se n1 + 1 posições. ao acessar n1, acessamos a posição de número n1 +1
                                            //com cópias desses subvetores, podemos mexer em A' sem tanto problema.
    
    int i = 0, j = 0;                       //índices para percorrer as cópias dos subvetores

    for (int k = p; k < r +1; ++k){         //percorreremos A' substituindo seus valores de forma a ordená-los
        if (L[i] <= R[j]){
            A[k] = L[i];                    //se o elemento de L for menor, jogamos ele em A'
            ++i;                            //incrementamos o iterador do subvetor L
        }
        else{
            A[k] = R[j];                    //se o elemento de R for menor, jogamos ele em A'
            ++j;                            //incrementamos o iterador do subvetor R
        }
    }
                                            //A cada iteração do for, o menor elemento entre os dois analisados é jogado em A'
                                            // se forem iguais, o elemento de L é jogado em A. quando chegar em algum elemento
                                            // de L que seja maior que o elemento de R, aí o de R é posto em A'.
                                            // sem perda de generalidade, quando L acaba, o iterador incrementa e faz com que o
                                            // elemento de L a ser analisado passe a ser o nosso "infinito", que é maior que todos
                                            // os outros elementos de A'. Por causa disso, a cada análise, apenas elementos de R
                                            // serão adicionados a A'(quando R acaba, o processo é análogo). Nenhum dos infinitos será
                                            // adicionado a A'. Isso porque, como são maiores que todos os elementos de A',
                                            // todos os n1+n2 elementos serão colocados em A' antes que os infinitos 
                                            // entrem no critério para entrarem em A'. como n1+n2 = tamanho de A', o 'for', que roda
                                            // exatas (tamanho de A') vezes, acaba antes, entregando apenas a lista ordenada
}

//========================================================================= MERGE SORT ==========================================================================
void merge_sort(int * A, int p, int r){ //recebe um ponteiro para uma lista, o indice de início e de fim do intervalo a ser analisado
    if(p < r){
        int q = (p+r)/2;               //divide o intervalo em dois

        merge_sort(A, p, q);           //chama a função recursivamente até que p=r (lista de um único elemento), quando a função retorna para a chamada acima e
        merge_sort(A, q+1, r);         //chama a função para a outra metade recursivamente

        merge(A, p, q, r);             //junta inicialmente duas listas de um elemento, em uma lista ordenada de dois elementos e, conforme retorna das chamadas
                                        // da merge_sort, junta listas ordenadas duas a duas em listas únicas ordenadas. Por fim, ordena a lista completa.
    }
}

//======

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


    merge_sort(L, 0, n-1); //ordena a lista
    printa_lista(L, n);    //imprime a lista ordenada
}
