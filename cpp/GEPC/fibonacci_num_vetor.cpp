#include <bits/stdc++.h>
using namespace std;
int main(){
    long fibonacci[61];
    int T;
    for (int j = 0; j <= 60; ++j){
        if(j == 0){
            fibonacci[0] =  0;
        }
        else if (j == 1){
            fibonacci[1] = 1;
        }
        else{
            fibonacci[j] = fibonacci[j - 1] + fibonacci[j - 2];
        }
    }
    cin >> T;
    int N[T];
    for(int i = 0; i < T; ++i){
        cin >> N[i];
    }
    for(int i = 0; i < T; ++i){
        cout << "Fib(" << N[i] << ") = " << fibonacci[N[i]] << endl;
    }
}
