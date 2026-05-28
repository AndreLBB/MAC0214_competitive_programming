// https://usaco.org/index.php?page=viewproblem2&cpid=944
#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& x, vector<int>& y,  int& min_x, int& max_x, int& min_y, int& max_y) {
             
    visited[u] = true;
    
    min_x = min(min_x, x[u]);
    max_x = max(max_x, x[u]);
    min_y = min(min_y, y[u]);
    max_y = max(max_y, y[u]);
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited, x, y, min_x, max_x, min_y, max_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    vector<int> x(V), y(V);
    
    for (int i = 0; i < V; i++){
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(V, false);
    int menor_perimetro = INT_MAX; 
    
    for (int i = 0; i < V; i++){
        if (!visited[i]){
            int min_x = INT_MAX, max_x = 0;
            int min_y = INT_MAX, max_y = 0;
            
            DFS(i, adj, visited, x, y, min_x, max_x, min_y, max_y);
            
            int perimetro = 2 * ((max_x - min_x) + (max_y - min_y));
            menor_perimetro = min(menor_perimetro, perimetro);
        }
    }    
    
    cout << menor_perimetro << "\n";
    return 0;
}
