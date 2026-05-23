#include <bits/stdc++.h>
using namespace std;
int main (){
    int n, custo, receita, ld;
    while (cin >> n >> custo){
        int lucro = 0, last_lucro = 0;
        for (int i = 0; i < n; ++ i){
            cin >> receita;
            ld = receita - custo;
            if (lucro + ld <= 0){
                lucro = 0;
            }
            else if (last_lucro < lucro + ld){
                last_lucro = lucro + ld;
                lucro = lucro + ld;
            }    
            else{
                lucro = lucro + ld;
            }
        }
        cout << last_lucro << endl;
    }
}
