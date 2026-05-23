#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q, caso = 1;
    while (cin >> n >> q){
        if (n != 0 || q != 0){
            vector <int> dp (10000, -1);
            int marmore [n], n_do_marmore;
            for (int i = 0; i < n; ++i){
                cin >> marmore[i];
            }
            sort (marmore, marmore + n);
            for (int i = 0; i < n; ++i){
                if (dp[marmore[i]] == -1){
                    dp[marmore[i]] = i + 1;
                }
            }
            cout << "CASE# " << caso << ":" << endl;
            for (int i = 0; i < q; ++i){
                cin >> n_do_marmore;
                if (dp[n_do_marmore] == -1){
                    cout << n_do_marmore << " not found" << endl;
                }
                else{
                    cout << n_do_marmore << " found at " << dp[n_do_marmore] << endl;
                }
            }
        }
        else {break;}
        ++caso;
    }
}
