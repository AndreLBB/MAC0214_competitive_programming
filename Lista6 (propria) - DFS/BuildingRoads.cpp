// https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;

void DFS(int i, vector<vector<int>>& adj, vector<bool>& visited){
    visited[i] = true;
    for (int v: adj[i]){
        if (!visited[v]){
            DFS(v,adj,visited);
        }
    }

}

int main(){

    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V);
    for (int i = 0;i<E;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V);
    int num_componente = 0;
    vector<int> representativos;
    for (int i = 0;i<V;i++){
        if (!visited[i]){
            DFS(i,adj,visited);
            num_componente++;
            representativos.push_back(i);
        }
    }
    cout<<num_componente-1<<"\n";
    if (num_componente-1 != 0){
        for (int i = 1;i<representativos.size();i++){
            cout << representativos[i-1]+1<<" "<< representativos[i]+1;
            cout<<"\n";
        }
        cout<<"\n";
    }
}
