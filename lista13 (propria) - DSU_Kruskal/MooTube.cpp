// https://usaco.org/index.php?page=viewproblem2&cpid=789
#include <bits/stdc++.h>
# define ll long long
using namespace std;

// Basicamente vc tem uma árvore, e vc vai ter Q queries
// Numa querie ele esscolhe um vértice e quer saber quantos
// vertices ele consegue alcançar com custo do caminho maior
// ou igual que k_i, sendo o custo do caminho o menor peso
// no caminho

class DSU {
    public:
	vector<int> parent;
	vector<int> size;
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
struct Edge{
    ll from;
    ll to;
    ll w;
};

struct Querie{
    ll k;
    ll v;
    ll i;
};

bool cmp_edge(Edge a, Edge b){
    return a.w>b.w; // pq queremos do maior peso
    // pro menor pq o de maior peso é menos "precioso"
    // que o de menor
}

bool cmp_querie(Querie a, Querie b){
    return a.k>b.k; // a gente quer ordenar pelo maior k
    // pq um k grande restringe o numero de edges, mas 
    // um pequeno nao
}

int main(){

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ll N,Q;
    cin>>N>>Q;
    vector<Edge> edges(N-1);
    for (ll i = 0;i<N-1;i++){
        ll from,to,w;
        cin>>from>>to>>w;
        from--;to--;
        Edge e;
        e.from = from;
        e.to = to;
        e.w = w;
        edges[i] = e;
    }
    vector<Querie> queries(Q);
    for (ll i = 0;i<Q;i++){
        Querie q;
        cin>>q.k>>q.v;
        q.v--;
        q.i = i;
        queries[i] = q;
    }
    vector<ll> respostas(Q);
    sort(edges.begin(), edges.end(), cmp_edge);
    sort(queries.begin(), queries.end(), cmp_querie);

    DSU dsu = DSU(N);
    ll j = 0;
    for (ll i =0; i< Q;i++){
        ll k = queries[i].k;
        while (j<N-1 && edges[j].w>=k){
            dsu.unite(edges[j].from,edges[j].to);
            j++;
        }
        respostas[queries[i].i] = dsu.size[dsu.find(queries[i].v)] - 1;
    }
    for (ll resposta: respostas){
        cout<<resposta<<"\n";
    }
}
