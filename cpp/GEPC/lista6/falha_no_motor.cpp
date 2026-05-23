#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, rpm, last_rpm = 0, counter = 0;
    bool queda = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> rpm;
        if (last_rpm > rpm && queda == 0){
            queda = 1;
            counter = i;
        }
         else if (last_rpm <= rpm){
            last_rpm = rpm;
        }
    }
    cout << counter << endl;
}
