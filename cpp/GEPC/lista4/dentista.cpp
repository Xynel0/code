#include <bits/stdc++.h>
using namespace std;
int main(){
    // recebe quantas consultas foram marcadas e seus horários
    int n;
    int fim;
    int aux0;
    int aux1;
    cin >> n;
    int horarios_originais[n][2];
    for(int i = 0; i < n; ++i){
        cin >> horarios_originais[i][0];
        cin >> horarios_originais[i][1];
    }

    //organiza a matriz com os horários
    for(int i = 0; i < n; ++i){
        int min_finder = horarios_originais[i][1]; //guarda o primeiro valor para ser comparado com os demais
        int indice_menor = i; //guardará o indice do menor valor para efetuar a troca

        //testa se o min_finder é maior que cada elemento dos horários de término da consulta
        for(int j = i; j < n; ++j){
            // se sim, min_finder assume o valor do menor em cada comparação e o indice do menor é atualizado
            if(min_finder > horarios_originais[j][1]){
                min_finder = horarios_originais[j][1];
                indice_menor = j;
            }
        }

        //troca o menor valor com o valor do início do array de horários
        aux0 = horarios_originais[i][0];
        aux1 = horarios_originais[i][1];
        horarios_originais[i][0] = horarios_originais[indice_menor][0];
        horarios_originais[i][1] = horarios_originais[indice_menor][1];
        horarios_originais[indice_menor][0] = aux0;
        horarios_originais[indice_menor][1] = aux1;
    }

    //conta quantas consultas será possível realizar
    int counter = 1;
    fim = horarios_originais[0][1];
    for (int i = 1; i < n; ++i){
        if (horarios_originais[i][0] >= fim){
            ++counter;
            fim = horarios_originais[i][1];
        }
    }
    cout << "RESULTADO:\n" << counter << endl;
}
