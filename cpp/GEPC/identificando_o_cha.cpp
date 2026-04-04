#include <bits/stdc++.h>
using namespace std;
int main(){
    int T, RESPOSTAS[5], corretos = 0;
    cin >> T;
    for(int i = 0; i < 5; ++i){
        cin >> RESPOSTAS[i];
        if(RESPOSTAS[i] == T){
            ++corretos;
        }
    }
    cout << corretos << endl;
}
