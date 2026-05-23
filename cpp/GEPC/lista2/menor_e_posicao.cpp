#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int menor;
    int indicemenor;
    cin >> N;
    int X[N];
    for(int i = 0; i < N; ++i){
        cin >> X[i];
    }
    menor = X[0];
    indicemenor = 1;
    for(int i = 0; i < N; ++i){
        if(X[i] < menor){
            menor = X[i];
            indicemenor = i;
        }
    }
    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << indicemenor << endl;
}
