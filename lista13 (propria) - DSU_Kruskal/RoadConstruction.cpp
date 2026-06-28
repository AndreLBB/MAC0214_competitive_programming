// https://cses.fi/problemset/task/1676
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class DSU {
	vector<int> parent;
	vector<int> size;
    public:
	int tamanho_maior_componente = 1;
    int num_componentes;
	DSU(int size_){
		parent = vector<int>(size_);
		size = vector<int>(size_,1);
		for (int i = 0; i < size_; i++) { 
			parent[i] = i; 
		}
        num_componentes = size_;
	}

	int find(int x){ 
		if (x == parent[x]) return x;
		parent[x] = find(parent[x]);
		return parent[x];
	}

	
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		if (size[x_root] < size[y_root]) swap(x_root, y_root);
		size[x_root] += size[y_root];
		parent[y_root] = x_root;
        num_componentes--; // pq aqui uniu duas componentes
        if (size[x_root]>tamanho_maior_componente){
            tamanho_maior_componente = size[x_root];
        }
		return true;
	}

	bool connected(int x, int y) { 
		return find(x) == find(y); 
	}
};

int main(){

    int n,m;
    cin>>n>>m;
    int a,b;
    DSU dsu = DSU(n);
    for (int i = 0;i<m;i++){
        cin>>a>>b;
        a--;b--;
        dsu.unite(a,b);
        cout<<dsu.num_componentes<<" "<<dsu.tamanho_maior_componente<<"\n";
    }
}