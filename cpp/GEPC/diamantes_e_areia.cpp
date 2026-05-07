#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int counter;
    string caso;
    bool control;
    cin >> n;
    int results[n];
    for (int i = 0; i < n; ++i){
        control = 1;
        counter = 0;
        cin >> caso;
        for (size_t j = 0; j < caso.length(); ++j){
            if (caso[j] == '.'){
                caso.erase(j, 1);
                --j;
            }
        }
        while (control == 1){    
            control = 0;    
            for (size_t j = 0; j < caso.length(); ++j){
                if (caso[j] == '<' && caso[j+1] == '>'){
                    caso.erase(j, 2);
                    ++counter;
                    --j;
                    control = 1;
                }
            }
        }
        results[i] = counter;
    }
    for (int i = 0; i < n; ++i){
        cout << results[i] << endl;
    }
}