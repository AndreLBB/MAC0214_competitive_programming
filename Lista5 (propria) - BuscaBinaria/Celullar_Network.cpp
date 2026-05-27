// https://codeforces.com/contest/702/problem/C
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> cities(n);
    vector<ll> towers(m);
    for (ll i = 0;i<n;i++) cin>> cities[i];
    for (ll i = 0;i<m;i++) cin>> towers[i];
    // 1 3 6 7 10 -> towers
    // cidade = 8
    // n seria tipo: pra cada cidade calcular a torre
    // mais perto dela, fazer isso pra todas cidades e
    // o r vai ser o maior desses valores
    ll maior = 0;
    for (ll cidade: cities){
        ll mais_proximo = -1;
        auto c = lower_bound(towers.begin(), towers.end(), cidade);
        if (c == towers.end()){
            mais_proximo = cidade - towers[m-1]; 
        }
        else{
            auto a = c-1;
            if (c == towers.begin()){
                mais_proximo = towers[0] - cidade;
            }
            else if (*c - cidade >= cidade - *a){
                mais_proximo = cidade - *a;
            }
            else{
                mais_proximo = *c - cidade;
            }
        }

        if (mais_proximo> maior){
            maior = mais_proximo;
        }
    }
    cout<<maior<<"\n";
return 0;
}
