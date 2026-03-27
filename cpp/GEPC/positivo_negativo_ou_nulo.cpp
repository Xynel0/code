#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int x;
    cout << "Insira x:" << endl;
    cin >> x;
    if (abs(x) > 1000)
    {
        cout << "valor absoluto excedido" << endl;
    }
    else if (x < 0){
        cout << "negativo" << endl;
    }
    else if (x == 0){
        cout << "nulo" << endl;
    }
    else{
        cout << "positivo" << endl;
    }
}
