#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, n1meros, r = 0;
    cout << "insira n:" << endl;
    cin >> n;
    if (n >= 1 && n <= 100){
        cout << "insira os números:" << endl;
        for (int i = 0; i < n; i++){
            cin >> n1meros;
            r = r + n1meros;
        }
    cout << r << endl;
    }
    else{
        cout << "quantidade de números inválida." << endl;
    }
}
