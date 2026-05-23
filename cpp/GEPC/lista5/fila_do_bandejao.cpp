#include <bits/stdc++.h>
using namespace std;
int main (){
    int n, k;
    while (cin >> n >> k){
        vector <int> fila, espacos;
        fila.push_back(0);
        for (int i = 1; i < n; ++i){
            int vai_p_fila;
            cin >> vai_p_fila;
            fila.push_back(vai_p_fila);
            espacos.push_back(fila[i] - fila[i-1]);
        }
        int total = fila[n-1];
        sort(espacos.begin(), espacos.end(), greater<int>());
        for (int i = 0; i < k - 1; ++i){
            total = total - espacos[i];
        }
        cout << total << endl;
    }
}
