// https://cses.fi/problemset/task/1195
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    
    vector<vector<pair<int, ll>>> adj(V);
    vector<vector<pair<int, ll>>> adj_rev(V);
    
    for (int i = 0; i < E; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj_rev[v].push_back({u, w});
    }

    vector<bool> processado_inicio(V, false);
    vector<ll> dist_inicio(V, LLONG_MAX);
    dist_inicio[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq_inicio;
    pq_inicio.push({0, 0});
    
    while (!pq_inicio.empty()){
        int v = pq_inicio.top().second;
        pq_inicio.pop();
        
        if (processado_inicio[v]) continue; 
        processado_inicio[v] = true;
        
        for (auto [k, w]: adj[v]){
            if (dist_inicio[k] > dist_inicio[v] + w){
                dist_inicio[k] = dist_inicio[v] + w;
                pq_inicio.push({dist_inicio[k], k});
            }
        }
    }

    vector<bool> processado_fim(V, false);
    vector<ll> dist_fim(V, LLONG_MAX);
    dist_fim[V-1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq_fim;
    pq_fim.push({0, V-1});
    
    while (!pq_fim.empty()){
        int v = pq_fim.top().second;
        pq_fim.pop();
        
        if (processado_fim[v]) continue; 
        processado_fim[v] = true;
        
        for (auto [k, w]: adj_rev[v]){
            if (dist_fim[k] > dist_fim[v] + w){
                dist_fim[k] = dist_fim[v] + w;
                pq_fim.push({dist_fim[k], k});
            }
        }
    }

    ll resp = LLONG_MAX;
    for (int u = 0; u < V; u++){
        for (auto [v, w] : adj[u]){
            if (dist_inicio[u] != LLONG_MAX && dist_fim[v] != LLONG_MAX){
                resp = min(resp, dist_inicio[u] + (w / 2) + dist_fim[v]);
            }
        }
    }

    cout << resp << "\n";
    return 0;
}