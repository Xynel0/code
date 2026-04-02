#include <bits/stdc++.h>
using namespace std;
int main(){
    int vetor[10];
    bool vetor_hunter[10];
    int x;
    int x_hunter = 0;
    for (int i = 0; i < 10; ++i){
        cout << "insira o " << i + 1 << "º valor:\n";
        cin >> vetor[i];
    }
    cout << "insira o valor X:\n";
    cin >> x;
    for (int i = 0; i < 10; ++i){
        vetor_hunter[i] = false;
        if(vetor[i] == x){
            ++x_hunter;
            vetor_hunter[i] = true;
        }
    }
    if(x_hunter == 0){
        cout << "Mia x\n";
    }
    else{
        cout << x_hunter << endl;
        for (int i = 0; i < 10; ++i){
            if(vetor_hunter[i] == true){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
