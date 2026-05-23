#include <bits/stdc++.h>
using namespace std;

int fib(int x, int &num_calls){
    ++num_calls;
    if(x == 0){
        return 0;
    }
    else if(x == 1){
        return 1;
    }
    else{
        return fib(x-1, num_calls) + fib(x-2, num_calls);
    }
}

int main(){
    int n;
    int result;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int ct;
        int num_calls = 0;
        cin >> ct;
        result = fib(ct, num_calls);
        cout << "fib(" << ct << ") = " << num_calls - 1 << " calls = " << result << endl;
    }
}
