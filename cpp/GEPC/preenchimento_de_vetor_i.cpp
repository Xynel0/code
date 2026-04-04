#include <bits/stdc++.h>
using namespace std;
int main(){
    long N[10];    
    cin >> N[0];
    for(int i = 1; i < 10; ++i){
        N[i] = N[i - 1]*2;
        cout << "N[" << i - 1 << "] = " << N[i - 1] << endl;
    }
    cout << "N[9] = " << N[9] << endl;
}
