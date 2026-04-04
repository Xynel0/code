#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int x;
    int in = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if (x >= 10 && x <= 20){
            ++in;
        }
    }
    cout << in << " in\n" << n - in << " out" << endl;
}
