#include <bits/stdc++.h>
using namespace std;
int main(){

    int n_total_fig; //define uma variável para o número de figurinhas que o álbum possui
    int fig_compradas; //define uma variável para o número de figurinhas adquiridas
    int fig_id; //define uma variável para armazenar o número específico (identificador) da figurinha
    int n_faltantes = 0; //define uma variável para armazenar o número de figurinhas faltantes

    //pede a quantidade de figurinhas que definirá o vetor
    cout << "insira o número total de figurinhas: \n"; 
    cin >> n_total_fig;

    //cria o vetor album com "n_total_fig" espaços e torna cada elemento do vetor igual a 0
    // (pois no começo o álbum não possui figurinhas)
    bool album[n_total_fig];
    for (int i = 0; i < n_total_fig; ++i){
        album[i] = false;
    }

    //pede a quantidade de figurinhas compradas
    cout << "insira a quantidade de figurinhas compradas: \n";
    cin >> fig_compradas;

    //para cada figurinha comprada, pede o id da figurinha (que pode ser de 1 a "n_total_fig")
    for (int i = 0; i < fig_compradas; ++i){
        cout << "insira o número da figurinha: \n";
        cin >> fig_id;
        //ainda para cada figurinha individual, compara o id com as posições existentes no álbum
        //se for um número que existe no álbum, marca o elemento de índice correspondente no vetor como 1
        if (fig_id > 0 && fig_id <= 10){
            album[fig_id - 1] = true;
        }
        //se não for um número entre 1 e "n_total_fig", imprime "figurinha inválida"
        else{
            cout << "figurinha inválida\n";
        }
    }

    //após a "colagem" das figurinhas, percorre cada elemento do vetor somando 1 a variável "n_faltantes" para cada elemento do vetor com estado "false"
    for (int i = 0; i < n_total_fig; ++i){
        if(album[i] == false){
            ++n_faltantes;
        }
    }
    //por fim, imprime a quantidade de figurinhas faltantes
    cout << "número de figurinhas faltantes:\n" << n_faltantes << endl;
}
