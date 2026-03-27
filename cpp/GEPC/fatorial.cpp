#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "insira n:" << endl;
    cin >> n;
        if (n > 0 && n <= 12){
            for (int i = n - 1; i > 0; i--)
            {
                n = n*i;
            }
            cout << n << endl;
        }
        else if (n == 0){
            cout << "1" << endl;
        }
        else{
            cout << "entrada inválida" << endl;
        }
}
