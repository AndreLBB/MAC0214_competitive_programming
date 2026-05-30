// https://usaco.org/index.php?page=viewproblem2&cpid=969
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <utility>
#define ll long long
using namespace std;

int main(){
    freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);

    int V, E;
    cin >> V >> E;
    
    vector<vector<pair<int, pair<int, int>>>> adj(V);
    for (int i = 0; i < E; i++){
        int u, v, c, f;
        cin >> u >> v >> c >> f;
        u--; v--;
        adj[u].push_back({v, {c, f}});
        adj[v].push_back({u, {c, f}});
    }

    double max_razao = 0.0;

    for (int F = 1; F <= 1000; F++) {
        vector<bool> processado(V, false);
        vector<int> dist_a_u(V, INT_MAX);
        dist_a_u[0] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()){
            int v = pq.top().second;
            pq.pop();
            
            if (processado[v]) continue; 
            processado[v] = true;
            
            for (auto edge : adj[v]){
                int k = edge.first;               
                int c = edge.second.first;        
                int f = edge.second.second;       
                
                if (f < F) continue;
                
                if (dist_a_u[v] != INT_MAX && dist_a_u[k] > dist_a_u[v] + c){
                    dist_a_u[k] = dist_a_u[v] + c;
                    pq.push({dist_a_u[k], k});
                }
            }
        }
        
        if (dist_a_u[V-1] != INT_MAX) {
            double razao = (double)F / dist_a_u[V-1];
            if (razao > max_razao) {
                max_razao = razao;
            }
        }
    }

    cout << (ll)(max_razao * 1000000.0) << "\n";
    
    return 0;
}