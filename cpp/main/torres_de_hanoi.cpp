#include <bits/stdc++.h>
using namespace std;

int hanoi (int x, int o, int a, int d){
    if (x == 1){
        cout << o << " - " << d << endl;
    }
    else{
        hanoi (x-1, o, d, a);
        cout << o << " - " << d << endl;
        hanoi (x - 1, a, o, d);
    }
    return 0;
}

int main(){
    int n;
    cout << "número de peças:\n";
    cin >> n;
    return (hanoi(n, 1, 2, 3));
}