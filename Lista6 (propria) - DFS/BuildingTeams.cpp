// https://cses.fi/problemset/task/1668
#include <bits/stdc++.h>
#define ll long long
using namespace std;


void DFS(int u,bool&da, vector<int>& cor, vector<vector<int>>& adj, vector<bool>& visited){
    for (int v: adj[u]){
        if (!visited[v]){
            cor[v] = !cor[u];
            visited[v] = true;
            DFS(v,da,cor,adj,visited);
        }
        else{
            if (cor[v]==cor[u]){
                da = false;
            }
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
    vector<int> cor(V,-1);
    bool da = true;
    for (int i = 0;i<V;i++){
        if (!visited[i]){
            cor[i] = 1;
            visited[i] = true;
            DFS(i,da,cor,adj,visited);
        }
    }
    if (!da){
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else{
        for (int i = 0;i<V;i++){
            cout << cor[i]+1<<" ";
        }
        cout<<"\n";
    }

}
