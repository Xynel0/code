#include <bits/stdc++.h>
using namespace std;
int main(){
    int n_atributos;
    while (cin >> n_atributos){   
        int m_cartas;
        int l_cartas;
        int carta_m;
        int carta_l;
        int atributo_sorteado;
        cin >> m_cartas;
        long m_carta_atributo [m_cartas][n_atributos];
        cin >> l_cartas;
        long l_carta_atributo [l_cartas][n_atributos];
        
        for(int i = 0; i < m_cartas; ++i){
            for (int j = 0; j < n_atributos; ++j){
                cin >> m_carta_atributo[i][j];
            }
        }

        for(int i = 0; i < l_cartas; ++i){
            for (int j = 0; j < n_atributos; ++j){
                cin >> l_carta_atributo[i][j];
            }
        }

        cin >> carta_m;
        cin >> carta_l;
        cin >> atributo_sorteado;

        if(m_carta_atributo[carta_m-1][atributo_sorteado-1] < l_carta_atributo[carta_l-1][atributo_sorteado-1]){
            cout << "Leonardo" << endl;
        }
        else if(m_carta_atributo[carta_m-1][atributo_sorteado-1] == l_carta_atributo[carta_l-1][atributo_sorteado-1]){
            cout << "Empate" << endl;
        }
        else if(m_carta_atributo[carta_m-1][atributo_sorteado-1] > l_carta_atributo[carta_l-1][atributo_sorteado-1]){
            cout << "Marcos" << endl;
        }
    }
}
