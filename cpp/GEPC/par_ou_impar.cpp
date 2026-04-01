#include <bits/stdc++.h>
using namespace std;
int main(){
    int b, c;
    bool r;
    cout << "quantidade de dedos que Bino usou:" << endl;
    cin >> b;
    if (b >= 0 && b <= 10){
        cout << "quantidade de dedos que Cino usou:" << endl;
        cin >> c;
        if (c >= 0 && c <= 10){
            r = (b + c);
            if (r % 2 == 0){
                cout << "Bino" << endl;
            }
            else{
                cout << "Cino" << endl;
            }
        }
        else if (c > 10){
            cout << "Dedo do pé não vale" << endl;
        }
        else{
            cout << "Entrada inválida";
        }
    }
    else if (b > 10){
        cout << "Dedo do pé não vale" << endl;
    }
    else{
        cout << "Entrada inválida";
    }
}
