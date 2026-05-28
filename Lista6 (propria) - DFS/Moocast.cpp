//https://usaco.org/index.php?page=viewproblem2&cpid=668

// Basicamente, existe uma aresta entre duas vacas 
// se a dist euclidiana entre elas for menor ou igual a p

#include <bits/stdc++.h>
using namespace std; 
#define ll long long

typedef struct{
    int x;
    int y;
    int p;
} vaca;

vaca cria_vaca(){
    vaca v;
    cin>>v.x>>v.y>>v.p;
    return v;
}

// se existe uma aresta de A para B
// e pelo enunciado pode ser que tenha aresta de A pra B
// mas nao de B pra A
// sqrt(delta_x^2 + delta_y^2) = dist
bool tem_aresta_a_pra_b(vaca a, vaca b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)  <=a.p * a.p;
}

void DFS(int i, int& contador,vector<bool>& visited, vector<vector<int>>& adj){
    visited[i] = true;
    contador++;
    for (int v: adj[i]){
        if (!visited[v]){
            DFS(v, contador,visited, adj);
        }
    }
}

int main(){

    freopen("moocast.in", "r",stdin);
    freopen("moocast.out", "w",stdout);

    int N;
    cin>>N;
    vector<vaca> vacas;
    
    for (int i = 0; i<N;i++){
        vacas.push_back(cria_vaca());
    }
    vector<bool> visited(N);
    vector<vector<int>> adj(N);
    for (int i = 0;i<N;i++){
        for (int j = 0;j<N;j++){
            if(i!=j && tem_aresta_a_pra_b(vacas[i], vacas[j])){
                adj[i].push_back(j);
            }
        }
    }
    vector<int> alcancaveis(N);
    int contador = 0;
    for (int i=0;i<N;i++){
        DFS(i,contador,visited, adj);
        alcancaveis[i] = contador;
        contador= 0;
        for (int j = 0;j<N;j++){
            visited[j] = false;
        }
    }
    int maior = 0;
    for (int valor: alcancaveis){
        if (valor> maior){
            maior = valor;
        }
    }
    cout<< maior<<"\n";

}
