#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////// FUNÇÕES AUXILIARES ///////////////////////////////////////////////////////

//recebe uma mensagem e um ponteiro para int, imprime a mensagem, recebe uma entrada e guarda na posição do ponteiro
void recebe_int(char msg[], int * elemento){
    printf("%s", msg);
    scanf("%d", elemento);
}

//recebe uma lista e seu tamanho e a imprime
void printa_lista(int * A, int n){
    printf("Vetor usado:\n[");
    for (int i = 0; i < n; ++i){
        if (i == n -1){
            printf("%d]\n\n", A[i]);
            return;
        }
        printf("%d, ", A[i]);
    }
}

//======================================================= ideia =======================================================
// a ideia da implementação da fila é usarmos um vetor sequencial como local de armazenamento.
// guardamos a posição do primeiro elemento para saber quem sairá quando solicitado, e do ultimo elemento +1
// para sabermos onde adicionar os cada próximo elemento. quando a ultima posição do vetor for ocupada,
// é possível que ainda haja espaço no início, em decorrência da possível eliminação de algum elemento.
// portanto, gerenciaremos esses casos afim de só considerarmos a fila cheia quando o vetor inteiro estiver cheio



/////////////////////////////////////////////////////// PARTE CENTRAL ///////////////////////////////////////////////////////

//declaração da estrutura fila
struct queue{
    int * vetor; //aponta para o vetor que guardará a fila
    int tam_max; //guarda a quantidade de elementos que podem ser guardados no vetor (!= da quantidade maxima da fila)
    int inicio;  //guarda o ÍNDICE de inicio DA FILA
    int final;   //guarda o ÍNDICE da proxima posição após ofinal DA FILA, ou seja, a primeira posição livre ao fim da fila

    //queremos guardar os elementos nas posições vetor[inicio, ..., fim-1]
};

typedef struct queue queue; //abreviamos struct queue apenas para queue


// verifica se a fila está vazia, retornando 1 se sim, e 0 se não
int empty_queue (queue * q){
    if (q->inicio == q->final){     //se o início for igual ao fim, sabemos que a fila está vazia.
        return 1;
    }
    return 0;                       //senão, a fila não está vazia
}

// para verificarmos se a fila está cheia, intuitivamente podemos pensar que, se todas as
// posições do vetor estão ocupadas a fila está cheia. mas como saber se todas as posições
// do vetor estão cheias? se o indice de fim der a volta no vetor e encontrar o indice de
// início, a fila estaria cheia. embora essa seja uma verdade, essa é exatamente a condição 
// de uma fila vazia. como fazemos para diferenciar nesses casos? podemos deixar uma posição
// do vetor intencionalmente vazia. dessa forma, esta ultima posição vazia seria guardada por
// 'fim', e se fim+1 == inicio, sabemos que a filaestá cheia. (a depender do caso, pode valer 
// a pena declarar o vetor com uma posição a mais que a capacidade pretendida)


// verifica se a fila está cheia de acordo com os critérios discutidos acima
int full_queue (queue * q){
    if ((q->inicio == 0 && q->final == q->tam_max -1) || q->final +1 == q->inicio){
        return 1;   
    }
                                // acima olhamos se 'inicio' é a posição
                                // inicial do vetor e o fim é a ultima posição
                                // do vetor. se esse for o caso, já sabemos que está
                                // cheio sem precisar acessar final+1, o que causaria
                                // acesso indevido

    return 0;   // se o vetor não cai em nenhum dos casos de estar cheio, retornamos 0
}

// adiciona mais um elemento à fila
void enqueue (queue * q, int elemento){
    if (full_queue(q)){                             //para adicionarmos um elemento à fila, verificamos primeiro se há espaço
        printf("ERRO: Queue Overflow!\n");
        return;
    }

    q->vetor[q->final] = elemento;                  // havendo espaço, podemos adicionar o elemento em q->final, pois ou ele está no fim do vetor com a
                                                    // posição 0 do vetor vazia, ou ele não está no fim do vetor com q->final+1 != inicio.
                                                    // daí, reajustamos q->final para a próxima posição

    if(q->final == q->tam_max -1){                  // se q->final está no fim do vetor (com full_queue falsa), a posição 0 do vetor está livre, isto é, inicio esta em alguma posição >= 1
        q->final = 0;                               // daí o fim da fila passa a apontar para a posição 0 do vetor.
        return;                                     // como adicionamos o elemento e modificamos o final, podemos voltar
    }
    ++ q->final;                                    // caso q-> final não seja a ultima posição do vetor, basta pular uma posição.
    return;
}

// remove o primeiro elemento da fila, retornando-o
int * dequeue (queue * q){
    if (empty_queue(q)){                            // primeiro vemos se a fila se encontra vazia
        printf("ERRO: Queue Underflow!");           // se sim, informamos que não é possível retirar um elemento
        return NULL;
    }
                                                    // se a fila não está vazia, podemos prosseguir
    int * keep_elemento = malloc (sizeof(int));     // criamos um ponteiro para um int que guardará o valor a ser retirado
    * keep_elemento = q->vetor[q->inicio];          // guardamos o valor atualmente em 'inicio' no int recém-alocado
    q->vetor[q->inicio] = 0;                        // zeramos o valor em 'inicio' (dispensável, mas preferi para ficar melhor de ver quando imprimir o vetor e a fila)

    // reajustando o inicio
    if (q->inicio == q->tam_max -1){                // se o inicio da fila estiver no fim do vetor, pulamos o inicio para 0
        q->inicio = 0;
    }
    else{                                           // senão, apenas incrementamos o inicio
        ++q->inicio;
    }
    return keep_elemento;                           // por fim, retornamos o ponteiro para o int que guarda o valor que foi removido
}

// recebe uma fila e a imprime
void print_queue (queue * q){
    printf("Fila:\n[");
    int i = q->inicio;                              //i irá percorrer a fila
    while (i != q->final){
        printf("%d, ", q->vetor[i]);
        if (i == q->tam_max -1){                    //se i chegar ao fim, fazemos i = 0 e continuamos
            i = 0;
            continue;
        }
        ++i;                                        // se i não está no fim, incrementamos apenas
    }
    printf("]\n");
}

// cria uma fila e seus atributos
queue * create_queue (int queue_max_size){          //recebe a quantidade de posições que o vetor terá
    queue * q = malloc(sizeof(queue));              //cria um ponteiro q que aponta para a fila recém alocada

    int * v = calloc(queue_max_size, sizeof(int));  //cria um ponteiro v que aponta para o inicio do vetor

    q->inicio = 0;                                  //define inicio da fila como 0
    q->final = 0;                                   //define fim da fila como 0
    q->tam_max = queue_max_size;                    //define tam_max
    q->vetor = v;                                   //faz q->vetor apontar para o vetor
    return q;                                       //retorna a estrutura
}

// apenas interação com o usuário (as partes relativas a fila estão comentadas)
int main(){
    int tam_vetor = -1;
    recebe_int("OLÁ! Este programa mostra uma implementação de fila em vetor.\nA cada passo, serão impressos tanto o vetor quanto a fila para uma melhor visualização.\nPara iniciar informe o tamanho do vetor a ser criado para guardar a fila.\nLembrando que se o vetor tem tamanho n, a fila terá no máximo n-1 elementos.\nApós isso, você poderá operar nesta fila.\nINSIRA O TAMANHO DO VETOR(INT):\n", &tam_vetor);
    while (tam_vetor <= 1){
        recebe_int("Insira um valor maior que 1:\n", &tam_vetor);
    }
    queue * fila = create_queue(tam_vetor);                                 //cria a estrutura fila

    printa_lista(fila->vetor, tam_vetor);
    print_queue(fila);


    int option = -1;
    printf("Agora que temos a fila criada... ");
        while (option != 0){
        recebe_int("Você pode\n1 - Ver apenas o vetor\n2 - Ver apenas a fila\n3 - Ver se a fila está vazia\n4 - Ver se a fila está cheia\n5 - Adicionar um elemento\n6 - Remover um elemento\n0 - Apagar a fila e sair\n\n======================================\nInsira sua escolha:\n", &option);
        if (option == 0){
            break;
        }
        if (option == 1){
            printa_lista(fila->vetor, tam_vetor);
            printf("\n");
        }
        else if (option == 2){
            print_queue(fila);
            printf("\n");
        }
        else if (option == 3){
            if (empty_queue(fila)){
                printf("Fila vazia\n\n");
                continue;
            }
            printf("Fila não vazia\n\n");
        }
        else if (option == 4){
            if (full_queue(fila)){
                printf("Fila cheia\n\n");
                continue;
            }
            printf("Fila não cheia\n\n");
        }
        else if (option == 5){
            int elemento;
            recebe_int("Insira o número que deseja adicionar à lista:\n", &elemento);
            enqueue(fila, elemento);
            printa_lista(fila->vetor, tam_vetor);
            print_queue(fila);
            printf("\n");
        }
        else if (option == 6){
            int * ret = dequeue(fila);
            if (ret == NULL){
                printf("Não foi possível eliminar um elemento da fila, pois ela estava vazia!\n");
                printa_lista(fila->vetor, tam_vetor);
                print_queue(fila);
                printf("\n");
                continue;
            }
            printf("O elemento retirado foi: %d\n", *ret);
            printa_lista(fila->vetor, tam_vetor);
            print_queue(fila);
            printf("\n");
        }
        else{
            printf("ERRO: OPÇÃO INVÁLIDA!\n\n");
        }
    }

    free(fila->vetor);                                          // libera o espaço do vetor usado pela fila
    free(fila);                                                 // libera o espaço usado pelo resto da fila
    printf("Tenha um bom dia (:\n");
}
