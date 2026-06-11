// https://cses.fi/problemset/task/1636
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Nao eh o numero de combinacoes considerando ordem (arranjo)
// eh o numero de combinacoes que tem uma ordem crescente
// cuidado que 1+1' n eh diferente de 1'+1

int main(){
    ll n,x;
    ll m = 1e9+7;
    cin>>n>>x;
    vector<ll> num(x+1,0);
    vector<ll> coins(n);
    for (int i =0;i<n;i++) cin>> coins[i];
    num[0] = 1;
    for(ll coin: coins){
        for (int i = coin;i<=x;i++){
            num[i] = (num[i] + num[i-coin]);
            num[i] %= m;
        }
    }
    cout<<num[x]<<"\n";
}