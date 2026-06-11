// https://cses.fi/problemset/task/2413
#include <bits/stdc++.h>
#define ll long long
using namespace std;


// parece o Counting tilings
// uma linha so depende da anterior, logo construcao interativa
// logo dp

/*
Tá então basicamente, se eu estou numa linha i e a
linha de baixo (i-1) não tem separação, eu tenho as
opções dois bloquinhos fechados, dois bloquinhos fechados
mas com o meio entre eles aberto, continuar o bloco
de baixo

Agora, se eu estou numa linha i e a linha de baixo (i-1) 
tem separação, eu tenho as opções, dois bloquinhos fechados,
dois bloquinhos fechados mas com o meio entre eles aberto, 
o bloquinho da esquerda aberto continuando o de baixo mas 
o da direita fechado e o da direita aberto continuando o de 
baixo mas o da esquerda fechado, os dois bloquinhos abertos 
continuando os de baixo ao mesmo tempo

*/

int main(){
    ll m = 1e9+7;
    int pior_caso = 1000000; // pior caso  (pra que tao dificil Deus, ja era dificil o suficiente)
    // pre computa a matriz pro pior caso
    vector<vector<ll>> matriz(pior_caso + 1, vector<ll>(2));
    matriz[1][0] = 1;
    matriz[1][1] = 1;
    
    for (int j = 2; j <= pior_caso; j++){
        matriz[j][0] = (2 * matriz[j-1][0] + matriz[j-1][1]) % m;
        matriz[j][1] = (matriz[j-1][0] + 4 * matriz[j-1][1]) % m;
    }
    /////
    // responde as queries com o que ja foi computado
    ll t;
    cin >> t;
    vector<ll> h(t);
    for (int i = 0; i < t; i++) {
        cin >> h[i];
    }
    
    for (int i = 0; i < t; i++){
        cout << (matriz[h[i]][0] + matriz[h[i]][1]) % m << "\n"; 
    }
    
    return 0;
}