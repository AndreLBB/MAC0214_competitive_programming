#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    
    // slidding window com prefix sum, a parte de sequência consecutiva é o que 
    // evidencia isso

    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    for (ll i=0;i<n;i++){
        cin>> a[i];
    }
    vector<ll> prefix_sum(n+1);
    prefix_sum[0] = 0;
    for (int k = 1;k<n+1;k++){
        prefix_sum[k] = prefix_sum[k-1] + a[k-1];
    }
    ll l = 0;
    ll tamanho_atual = 0;
    ll maior_tamanho = 0;

    for (ll r = 0; r < n; r++) {

        tamanho_atual++;

        while (prefix_sum[r + 1] - prefix_sum[l] > t) {
            l++;
            tamanho_atual--;
        }

        if (tamanho_atual > maior_tamanho) {
            maior_tamanho = tamanho_atual;
        }
    }

    cout << maior_tamanho << "\n";
    return 0;
}