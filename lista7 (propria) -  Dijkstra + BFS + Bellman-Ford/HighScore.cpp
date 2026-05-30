// https://cses.fi/ckvo8q5wh/task/1673
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct edge{
    ll from;
    ll to;
    ll w;
};

int main(){

    ll V,E;
    cin>>V>>E;

    vector<edge> edges(E);
    vector<vector<ll>> rev(V);

    vector<ll> dist(V, LLONG_MAX);
    dist[0] = 0;

    for (ll i = 0;i<E;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;

        edge e;
        e.from = u;
        e.to = v;
        e.w = -w;

        edges[i] = e;
        rev[v].push_back(u);
    }

    for (ll i = 0;i<V-1;i++){
        for (auto e: edges){
            if (dist[e.from]==LLONG_MAX) continue;
            if (dist[e.to]>dist[e.from]+e.w){
                dist[e.to] = dist[e.from]+e.w;
            }
        }
    }

    vector<bool> chega(V,false);

    queue<ll> q;
    q.push(V-1);
    chega[V-1] = true;

    while(!q.empty()){
        ll v = q.front();
        q.pop();

        for (auto u: rev[v]){
            if (!chega[u]){
                chega[u] = true;
                q.push(u);
            }
        }
    }

    bool tem_ciclo = false;

    for (auto e: edges){
        if (dist[e.from]==LLONG_MAX) continue;

        if (dist[e.to]>dist[e.from]+e.w){
            if (chega[e.to]){
                tem_ciclo = true;
            }
        }
    }

    if (tem_ciclo){
        cout<<-1<<"\n";
    }
    else{
        cout<<-dist[V-1]<<"\n";
    }
}