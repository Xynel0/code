# include <stdlib.h>
# include <stdio.h>

//  neste arquivo, buscamos implementar uma árvore binária de busca, além de alguns algoritmos de visita,
//  de pergunta e de modificação.
//
//  OBJETIVOS:
//      visita:
//          pré-ordem[x], pós-ordem[x], em ordem[x]
//      pergunta:
//          buscar[x], mínimo[x], máximo[x], sucessor[x], predecessor[x]
//      modificação:
//          transplante[x], inclusão[x], remoção[x]
//
//  lembrando, as propriedades da árvore binária de busca dizem que, para quaisquer nós x e y,
//      ==> se y estiver na sub-árvore esquerda de x, então o valor de y é <= valor de x
//      ==> se y estiver na sub-árvore direita de x, então o valor de y é >= valor de x


//  inicialmente, precisamos criar a struct do nó. cada nó possui o valor numérico, um pai,
//  um filho esquerdo e um filho direito, podendo estes campos estarem vazios ou não.

struct no {
    int valor;
    struct no * pai;
    struct no * esq;
    struct no * dir;
};

typedef struct no no;

//  para nos referirmos à arvore, basta se referirmos à raíz da árvore, que é um nó.
//  como é um único nó, não há necessidade de criar uma struct aqui para a árvore.

//=================================================================== VISITA ===================================================================

// a função recebe outra função como parâmetro, apenas para ser usada como o ato de visitar
void pre_order (no * raiz, void (* visita)(no *)){
    if (raiz != NULL){
        visita(raiz);                                       // se o nó não é nulo, executa a função visita
        pre_order(raiz->esq, visita);                       // visita, em pré-ordem a sub-árvore enraizada no filho esquerdo do nó
        pre_order(raiz->dir, visita);                       // visita, em pré-ordem a sub-árvore enraizada no filho direito do nó
    }
}

void in_order (no * raiz, void (* visita)(no *)){
    if (raiz != NULL){
        in_order(raiz->esq, visita);                        // se o nó não é nulo, visita em ordem a sub-árvore enraizada no filho esquerdo do nó
        visita(raiz);                                       // executa a função visita
        in_order(raiz->dir, visita);                        // visita em ordem a sub-árvore enraizada no filho direito do nó
    }
}

void post_order (no * raiz, void (* visita)(no *)){
    if (raiz != NULL){
        post_order(raiz->esq, visita);                      // se o nó não é nulo, visita em pós-ordem a sub-árvore enraizada no filho esquerdo do nó
        post_order(raiz->dir, visita);                      // visita em pós-ordem a sub-árvore enraizada no filho direito do nó
        visita(raiz);                                       // executa a função visita
    }
}


//=================================================================== PERGUNTA ===================================================================

// Buscar: retorna a posição de um nó na sub-árvore enraizada em x com o valor indicado ou nulo caso tal nó não exista
no * tree_search (no * x, int k){
    while (x != NULL && x->valor != k){
        if (k < x->valor){                  //se k < x.valor o nó com valor k está na esquerda ou não existe
            x = x->esq;
        }
        else{                               //se k não é menor que x.valor mas é igual, o while não executa e x é retornado
            x = x->dir;                     //se k não é menor nem igual, é maior e o nó de valor k está à direita ou não existe
        }
    }
    return x;                               //se alcançar nulo, o nó não existe, retornamos null. se alcançar o nó, retornamos o nó
}

// Mínimo: retorna a posição do nó com menor valor dentro da sub-árvore enraizada em x, ou nulo, caso não exista um menor (árvore vazia)
no * min_tree (no * x){
    while(x != NULL && x->esq != NULL){
        x = x->esq;
    }
    return x;
}

// Máximo: retorna a posição do nó com maior valor dentro da sub-árvore enraizada em x ou nulo, caso não exista um maior (árvore vazia)
no * max_tree (no * x){
    while (x != NULL && x->dir != NULL){
        x = x->dir;
    }
    return x;
}

// Sucessor: O sucessor de um nó x é o nó que é visitado após x em um percurso em ordem. Lembrando que o em ordem
// visita a sub-árvore esquerda, depois o nó, e por fim a sub-árvore direita. Dai o próximo nunca está à esquerda,
// nem enquanto filho nem enquanto pai, pois se algum nó y é pai à esquerda, isto é, possui sub-árvore à direita 
// na qual está x, a árvore direita, incluindo x só é visitada após o nó já ter sido visitado.
//
// para qualquer nó, ou o nó possui sub-árvore à direita, ou o nó não possui. se ele possui, o em ordem visita todos
// os nós à esquerda da raiz da sub-árvore antes de visitar a raíz e, portanto, o sucessor será o mínimo da sub-árvore à direita.
// se o nó não possui sub-árvore à direita, ou é o último ou não. Se não é o último, pela discussão acima, buscamos o primeiro nó
// acima de x tal que a sub-árvore com raiz no filho esquerdo do nó contenha x. (visualmente a primeira curva para a direita subindo a árvore)

no * next_node (no * x){
    if (x != NULL){
        if (x->dir != NULL){
            return min_tree(x->dir);
        }
        no * y = x->pai;
        while (y != NULL && y->dir == x){
            x = y;
            y = y->pai;
        }
        return y;
    }
    return NULL;
}

// Para o nó anterior, a lógica é análoga, porém inversa. no em ordem, visita-se a esquerda, depois o nó e depois a direita.
// daí, o nó anterior a x será o ultimo visitado da sub-árvore esquerda de x. se x não tiver árvore à esquerda, o anterior será
// o primeiro nó y acima de x tal que x esteja na sub-árvore direita de y. (visualmente se fizer o caminho até a raíz, será o nó
// após a primeira curva para a esquerda)
no * previous_node (no * x){
    if (x != NULL){
        if (x->esq != NULL){
            return min_tree(x->esq);
        }
        no * y = x->pai;
        while (y != NULL && y->esq == x){
            x = y;
            y = y->pai;
        }
        return y;
    }
    return NULL;
}

//============================================================================= MODIFICAÇÃO =============================================================================

// para realizarmos as operaões de modificação precisamos de uma função que cria um nó de acordo com a estrutura que definimos
no * create_node (int valor){
    no * x = malloc(sizeof(no));    //apenas aloca um espaço e retorna o ponteiro. As definições de pai e filhos devem ser feitas por quem
    x->valor = valor;               //solicitou a criação do nó
    return x;
}

// INCLUSÃO: recebe a raiz de uma BST e retorna a raiz da BST com o elemento incluido
no * include_node (no * raiz, no * a_incluir){
    if (a_incluir == NULL){                                             // se o elemento a incluir for nulo, não há o que incluir
        printf("ERRO: não é possível incluir um nó nulo!\n");
        return raiz;
    }
    if (a_incluir->dir != NULL || a_incluir->esq != NULL){                                             // se o elemento a incluir for nulo, não há o que incluir
        printf("ERRO: não é possível incluir com filhos\n");
        return raiz;
    }
    
    no * keep_last = NULL;                                              // definimos um ponteiro para guardar o ultimo nó pelo qual passarmos
    no * x = raiz;                                                      // ao descer na árvore e um que vai "ativamente descer na árvore"

    while (x != NULL){                                                  // Lembrando que a árvore pode não ter nenhum elemento. Nesse caso, o procedimento pula o while
        keep_last = x;                                                  // último recebe x
        if (a_incluir->valor < x->valor){                               // se o valor a inlcuir for menor que o atual, desce para a esquerda. do contrário, para a direita
            x = x->esq;                                                 // até que x seja null. quando isso acontecer, o último terá guardado o nó que será pai do novo nó
        }
        else{
            x = x->dir;
        }
    }
    a_incluir->pai = keep_last;                                         // fazemos o pai do nó a incluir ser o ultimo visitado por x
    if (keep_last == NULL){                                             // e decidimos em qual lado desse nó ficará o novo nó
        return a_incluir;
    }
    if (a_incluir->valor < keep_last->valor){
        keep_last->esq = a_incluir;
    }
    else{
        keep_last->dir = a_incluir;
    }
    return raiz;                                                        // retornamos a raiz
}

// Procedimento de transplante: troca a subárvore enraizada em u por uma subárvore enraizada em v
// vejamos:

no * transplante (no * raiz, no * u, no * v ){
    if (u != NULL){
        if (u->pai == NULL){
            raiz = v;
            return raiz;
        }
        else if (u == u->pai->dir){
            u->pai->dir = v;
        }
        else{
            u->pai->esq = v;
        }
        if (v != NULL){
            v->pai = u->pai;
        }
        return raiz;
    }
    printf("ERRO: não é possivel substituir um nó inexistente\n");
    return raiz;
}

// Para a exclusão, dado um nó x, há alguns casos:
//      x é nulo: já não está incluso
//      x não tem pai: na verdade, x->pai = NULL. para nossos procedimentos, podemos tratá-lo como um nó com pai
//      x tem 0 filhos: basta apontar o filho esquerdo ou direito do pai de x para nulo
//           |         |
//          ()   =>  NULL
//      x tem um filho: fazemos esse filho assumir o lugar do pai, com o transplante
//           |         |
//          (X)  =>   (F)
//         /
//       (F)
//      x tem os dois filhos: trocamos x com o mínimo da direita ou o máximo da esquerda
//           |         |
//          (X)  =>   (M)
//         /  ||     /  ||
//      (Fe)  (Fd) (Fe) (Fd)

// como fazer o mínimo da direita assumir o lugar de x?
// chamemos o nó mínimo de y. se y tem filho, é o filho direito, que é >= y E <=y->pai, assim como os possíveis filhos desse nó direito.
// portanto podemos simplesmente direcionar o filho esquerdo do pai de y para a subárvore direita de y. com isso, y está livre
// daí substituimos cada atributo de y (exceto o valor) pelos atributos de x e os respectivos pais e filhos dos nós ao redor de x.




// EXCLUSÃO: recebe a raiz de uma BST e retorna a raiz da BST com o elemento exncluido
no * exclude_node (no * raiz, no * a_remover){
    if (a_remover == NULL){
        printf("O nó a ser removido não existe. Portanto, nada foi feito!\n");
        return raiz;
    }
    if (a_remover->esq == NULL){                                // cobre os casos 0 filhos e só filho direito
        raiz = transplante (raiz, a_remover, a_remover->dir);   // corrige os ponteiros acima de a_remover->dir
    }
    else if (a_remover->dir == NULL){
        raiz = transplante (raiz, a_remover, a_remover->esq);   // corrige os ponteiros acima de a_remover->esq
    }
    else{
        no * y = next_node(a_remover);                          // guarda o endereço do nó após o a_remover.
        raiz = transplante(raiz, y, y->dir);                    // faz a sub-árvore y->dir assumir a posição de y no encadeamento da árvore principal
                                                                // y->pai e y->dir ainda apontam pro mesmo canto. como y é o menor da direita de a_remover, y não tem esquerda
        //começamos a colocar y no lugar do a_remover
        a_remover->esq->pai = y;                    // transferimos a paternidade do filho esquerdo para y
        y->esq = a_remover->esq;                    // fazemos y reconhecer como filhos os filhos de a_remover
        y->dir = a_remover->dir;
        if (a_remover->dir != NULL){                //se a_remover->dir não tiver filhos originalmente, o transplante acima torna este if falso
            a_remover->dir->pai = y;                //caso tenha ficado alguém em a_remover->dir, faz o pai desse alguém apontar para y 
        }
        raiz = transplante (raiz, a_remover, y);    // corrige os ponteiros acima de y, mudando junto o ponteiro y->pai
    }
    free(a_remover);        //note que no processo, os campos de a_remover não foram alterados. aqui, liberamos o espaço por ele ocupado.
    return raiz;
}

void printa_no(no * x){
    printf("%d, ", x->valor);
}

void printa_arv(no * raiz){
    printf("[");
    in_order(raiz, printa_no);
    printf("]\n");
}

//algumas interações com a árvore para fins de teste
int main (){
    no * raiz = include_node(NULL, create_node(2));
    printa_arv(raiz);
    raiz = include_node(raiz, create_node(7));
    printa_arv(raiz);
    raiz = include_node(raiz, create_node(5));
    printa_arv(raiz);
    raiz = include_node(raiz, create_node(3));
    printa_arv(raiz);
    raiz = include_node(raiz, create_node(12));
    printa_arv(raiz);
    no * x = create_node(4);
    raiz = include_node(raiz, x);
    printa_arv(raiz);
    raiz = include_node(raiz, create_node(12));
    printa_arv(raiz);
    raiz = include_node(raiz, create_node(67));
    printa_arv(raiz);
    raiz = exclude_node(raiz, x);
    printa_arv(raiz);
}
