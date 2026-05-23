#include <bits/stdc++.h>
using namespace std;

long fatorial(int X){
    long f;
    if(X == 0 || X == 1){
        f = 1;
    }
    else{
        f = X * fatorial(X-1);
    }
    return f;
}

long soma_f(int M, int N){
    long soma = fatorial(M) + fatorial(N);
    return soma;
}
int main(){
    int M;
    int N;
    long soma_dos_fatoriais;
    while (cin >> M){
        cin >> N;

    soma_dos_fatoriais = soma_f(M, N);
    cout << soma_dos_fatoriais << endl;
    }
}
