// https://cses.fi/problemset/task/1675
#include <bits/stdc++.h>
#define ll long long
using namespace std;



class DSU {
    public:
	vector<int> parent;
	vector<int> size;
    ll custo_total = 0;
	DSU(int size_){
		parent = vector<int>(size_);
		size = vector<int>(size_,1);
		for (int i = 0; i < size_; i++) { 
			parent[i] = i; 
		}
	}

	int find(int x){ 
		if (x == parent[x]) return x;
		parent[x] = find(parent[x]);
		return parent[x];
	}

	
	bool unite(int x, int y, ll custo) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		if (size[x_root] < size[y_root]) swap(x_root, y_root);
		size[x_root] += size[y_root];
		parent[y_root] = x_root;
        custo_total += custo;
		return true;
	}

	bool connected(int x, int y) { 
		return find(x) == find(y); 
	}
};

struct edge{
    ll from;
    ll to;
    ll w;
};

bool cmp(edge a, edge b){
    return a.w<b.w;
}

int main(){

    ll n,m;
    cin>> n>> m;
    vector<edge> edges(m);
    for (ll i = 0;i<m;i++){
        edge e;
        cin>>e.from>>e.to>>e.w;
        e.from--;e.to--;
        edges[i] = e;
    }
    sort(edges.begin(), edges.end(),cmp);
    DSU dsu = DSU(n);
    for (ll i = 0;i<m;i++){
        if (!dsu.connected(edges[i].from,edges[i].to)){
            dsu.unite(edges[i].from,edges[i].to, edges[i].w);
        }
    }
    if (dsu.size[dsu.find(0)] != n){
        cout<<"IMPOSSIBLE"<<"\n";
    } 
    else{
        cout<<dsu.custo_total<<"\n";
    }

}