#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;

    //recebe n
    cout << "insira n:" << endl;
    cin >> n;
    //se n for maior que 0 e estiver dentro do intervalo válido...
    if (n > 0 && n <= 12){
        //realiza o fatorial
        for (int i = n - 1; i > 0; i--){
            n = n*i;
        }
        cout << n << endl; //imprime o resultado
    }
    //se n for 0, imprime 1
    else if (n == 0){
        cout << "1" << endl;
    }
    else{
        cout << "entrada inválida" << endl;
    }
}
