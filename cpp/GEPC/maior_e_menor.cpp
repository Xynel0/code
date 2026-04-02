//recebe um valor n, depois n valores x e, por fim, imprime o maior e o menor valor
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x, maior, menor; //define variáveis

    //recebe o valor de n
    cout << "insira o valor de n:\n";
    cin >> n;

    if(n > 0 && n <= 100){
        int lista[n]; //gera um vetor de tamanho n

        //atribui a cada elemento i do vetor um valor x inserido pelo usuário
        for(int i = 0; i < n; ++i){
            cout << "insira o valor do " << i + 1 << "º x:\n";
            cin >> x;
            if(n > 0 && n <= 100){
                lista[i] = x;
            }
            else{
                cout << "valor de x inválido" << endl;
            }
        }

        //atribui a ambas as variáveis o valor do primeiro elemento de "lista[n]"
        maior = lista[0];
        menor = lista[0];

        //verifica se o elemento i do vetor "lista[n]"...
        for(int i = 0; i < n; ++i){
            //...é maior que o valor atual de "maior"
            if(maior < lista[i]){
                maior = lista[i]; //troca "maior" pelo novo maior
            }
            //...é menor que o valor atual de "menor"
            if(menor > lista[i]){
                menor = lista[i]; //troca "menor" pelo novo menor
            }
        }
        //imprime ambos os valores
        cout << "maior:\n" << maior << endl;
        cout << "menor:\n" << menor << endl;
    }
    else{
        cout << "valor de n inválido";
    }
}
