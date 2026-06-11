// https://usaco.org/index.php?page=viewproblem2&cpid=993
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;
    
    vector<int> mooney(n);
    for (int i = 0; i < n; i++){
        cin >> mooney[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<vector<ll>> lucro_maximo(1001, vector<ll>(n, -1));
    lucro_maximo[0][0] = 0;

    for (int t = 0; t < 1000; t++){
        for (int u = 0; u < n; u++){
            if (lucro_maximo[t][u] != -1){
                for (int v : adj[u]){
                    lucro_maximo[t+1][v] = max(lucro_maximo[t+1][v], lucro_maximo[t][u] + mooney[v]);
                }
            }
        }
    }

    ll max_lucro = 0;
    
    for (ll t = 0; t <= 1000; t++){
        if (lucro_maximo[t][0] != -1){
            ll lucro = lucro_maximo[t][0] - c * t * t;
            if (lucro > max_lucro) {
                max_lucro = lucro;
            }
        }
    }

    cout << max_lucro << "\n";
    
    return 0;
}