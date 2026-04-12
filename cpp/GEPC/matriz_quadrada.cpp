#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    
    while (true){
        cin >> n;
        if(n != 0){            
            int matriz [n][n];
            
            for (int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    matriz[i][j] = 1 + min(min(i, j), min(n-1-i, n-1-j));
                }
            }
            
            for(int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    if (matriz[i][j] < 10){
                        if (j == n-1){
                            cout << "  " << matriz[i][j] << endl;
                        }
                        else{
                            cout << "  " << matriz[i][j] << " ";
                        }
                    }
                    else if (j == n-1){
                        cout << " " << matriz[i][j] << endl;
                        }
                    else{
                        cout << " " << matriz[i][j] << " ";
                    }    
                }
            }
            cout << endl;
        }
        else{
            return 0;
        }
    }
}
