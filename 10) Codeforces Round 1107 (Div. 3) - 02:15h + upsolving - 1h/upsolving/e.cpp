#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& tamanho, vector<int>& parent) {
    tamanho[u] = 1;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, adj, tamanho, parent);
            tamanho[u] += tamanho[v];
        }
    }
}

int main() {

    vector<bool> eh_quadrado(1000005, false);
    for (ll i = 1; i * i <= 1000000; i++) {
        eh_quadrado[i * i] = true;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n + 1);
        vector<vector<int>> adj(n + 1);
        vector<int> tamanho(n + 1, 0);
        vector<int> parent(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0, adj, tamanho, parent);

        ll resposta = 0;
        for (int u = 1; u <= n; u++) {
            if (eh_quadrado[a[u]]) {
                vector<ll> ramos;
                
                for (int v : adj[u]) {
                    if (v == parent[u]) {
                        ramos.push_back(n - tamanho[u]);
                    } else {
                        ramos.push_back(tamanho[v]);
                    }
                }

                ll soma1 = 0, soma2 = 0, soma3 = 0;
                for (ll x : ramos) {
                    soma1 += x;
                    soma2 += x * x;
                    soma3 += x * x * x;
                }

                ll e2 = (soma1 * soma1 - soma2) / 2;
                ll e3 = (soma1 * soma1 * soma1 - 3 * soma1 * soma2 + 2 * soma3) / 6;
                resposta += e2 + e3;
            }
        }

        cout << resposta << "\n";
    }
}