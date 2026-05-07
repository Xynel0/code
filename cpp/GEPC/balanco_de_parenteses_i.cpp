#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    while(cin >> n){
        bool incorrect = 0;
        int counter = 0;
        for (size_t i = 0; i < n.length(); ++i){
            if (counter < 0){
                incorrect = true;
                break;
            }
            else{
                if (n[i] == '('){
                    ++counter;
                }
                else if (n[i] == ')'){
                    --counter;
                }
            }
        }
        if (counter == 0 && incorrect == false){
            cout << "correct" << endl;
        }
        else{
            cout << "incorrect" << endl;
        }
    }
}