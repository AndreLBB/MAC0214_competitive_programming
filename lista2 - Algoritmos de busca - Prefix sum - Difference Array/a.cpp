#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long


int da_pra_cortar_em_k(vector<ll>& v, ll x, ll k){
    ll cortes = 0;
    ll soma = 0;
    for (int i = 0;i< (ll)v.size();i++){
        if (v[i]>x){
            return 0;
        }
        else if (soma + v[i]>x){
            soma = v[i];
            cortes++;
        }
        else{
            soma+=v[i];
        }
    }
    if (cortes +1 <= k){
        return 1;
    }
    else return 0;
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    
    // ter uma f(x) que diz dá pra cortar o array em k partes
    // em que cada parte tem valor no máximo x. E aí fazer busca
    // binária na resposta com x começando da soma dos elementos do array
    ll n,k;
    cin >> n>>k;
    ll soma = 0;
    vector<ll> v(n);
    for (ll i = 0;i<n;i++){
        cin>>v[i];
        soma += v[i];
    }
    ll x = 0;
    for (ll b = soma; b >= 1; b /= 2) {
        while (da_pra_cortar_em_k(v, x+b, k) == 0) x += b;
    }
    ll w = x+1;
    cout<< w<<"\n";
    return 0;
}