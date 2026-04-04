#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    vector <int> carneiros_em;
    vector <bool> atacadas;
    int total_atacadas = 0;
    int nao_roubadas = 0;
    int estrela_atual = 0;
    int proxima_estrela;
    cin >> N;
    
    for(int i = 0; i < N ; ++i){
        int x; cin >> x;
        carneiros_em.push_back(x);
        atacadas.push_back(false);
    }

    while (estrela_atual >= 0 && estrela_atual < N){
        if (carneiros_em[estrela_atual] % 2 == 1){
            proxima_estrela = estrela_atual + 1;
        }
        else{
            proxima_estrela = estrela_atual - 1;
        }
        
        if (carneiros_em[estrela_atual] > 0){
            --carneiros_em[estrela_atual];
            atacadas[estrela_atual] = true;
        }
        estrela_atual = proxima_estrela;
    }
  
    for (size_t i = 0; i < carneiros_em.size(); ++i){
        nao_roubadas = nao_roubadas + carneiros_em[i];
    }
    for (size_t i = 0; i < atacadas.size(); ++i){
        if (atacadas[i] == true){
            ++total_atacadas;
        }    
    }
    cout << total_atacadas << " " << nao_roubadas << endl;
}
