// https://cses.fi/problemset/task/1142/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// a grande ideia é para cada tábua calcular qual a maior
// área que é possível obter tendo como altura a altura dessa
// tábua. 
// Nesse caso, tábuas de altura maior que a atual tudo bem pq
// a gente pode só ignorar a altura extra, mas tábuas menores
// impedem a gente de continuar e por isso precisamos saber
// qual o próximo elemento de altura menor que o atual na
// direita e esquerda do atual oque leva ao nearest smaller 
// value

// Sendo que o nearest smaller value basico é só pra esquerda
// como queremos direita e esquerda podemos ter duas 
// pilhas monotonicas uma começando da esquerda e outra da direita
// ou notar que quando um elemento é expulso da pilha
// o cara que o expulsou é o nearest smaller vallue da direita

int main(){

    ll n;
    cin>>n;
    vector<pair<ll,ll>> k(n);
    for (ll i = 0;i<n;i++) {
        cin>>k[i].first;
        k[i].second = i;
    }
    stack<pair<ll,ll>> s;
    s.push({-1, -1}); // poderia ser {-1,0} mas ai teria que ajustar o calculo da largura
    vector<ll> indice_do_menor_esquerda(n,-1);
    vector<ll> indice_do_menor_direita(n,-1);
    for (ll i = 0;i<n;i++){
        while (s.top().first>=k[i].first){
            indice_do_menor_direita[s.top().second] = i;
            s.pop();
        }
        indice_do_menor_esquerda[i] = s.top().second;
        s.push(k[i]);
    }
    // calcula a area
    // Um problema é que o último cara a ser colocado na pilha
    // tem o seu indice_do_menor_direita atualizado
    // nem no caso do menor estar tipo no meio do array
    // então, vamos usar que se for -1 é pq sua área vai até
    // o final
    // 1 5 6 4 5 3 
    // l = 0
    // r = 5
    vector<ll> areas(n);
    for (ll i = 0;i<n;i++){
        if (indice_do_menor_direita[i]==-1){
            indice_do_menor_direita[i] = n; // poderia ser n-1, mas ai teria que ajustar o calculo da largura
        }
        areas[i] = (indice_do_menor_direita[i] - indice_do_menor_esquerda[i]-1) * k[i].first;
    }
    // pega o máximo
    ll max = 0;
    for (ll v : areas){
        if (v>max) max = v;
    }
    cout<<max<<"\n";
}
