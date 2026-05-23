#include <bits/stdc++.h>
using namespace std;
const int max_v = 10000;

vector <int> adj[max_v];
vector <bool> vis(max_v, false);
    
void dfs_iterativa(int inicio) {
    stack<int> s;
    s.push(inicio);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!vis[u]) {
            vis[u] = true;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    s.push(v);
                }
            }
        }
    }
}

int main(){
    int n, m;
    if (!(cin >> n >> m)){
        return 0;
    }
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int componentes = 0;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs_iterativa(i);
            ++componentes;
        }
    }
    cout << componentes << endl;
}
