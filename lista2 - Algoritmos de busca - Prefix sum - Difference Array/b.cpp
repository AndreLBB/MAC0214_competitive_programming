#include <algorithm>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    

    // ordenar pelos maiores, montar prefix sum, fazer busca binária no prefix sum
    // da quantidade de doce e devolver o indice encontrado na busca
    ll t,n,q;
    cin >> t;
    for (ll i = 0; i<t;i++){
        cin >> n >> q;
        vector<ll> v(n);
        for (ll j = 0; j< n;j++){
            cin >> v[j];
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<ll> prefix_sum(n);
        for (int k = 0;k<n;k++){
            if (k == 0){
                prefix_sum[k] = v[0];
            }
            else{
                prefix_sum[k] = prefix_sum[k-1] + v[k];
            }
        }
        for (ll j = 0;j<q;j++){
            ll acucar;
            cin>> acucar;
            auto it = lower_bound(prefix_sum.begin(),prefix_sum.end(), acucar);
            if (it == prefix_sum.end()){
                cout << -1 << "\n";
            }
            else{
                ll indice = (it - prefix_sum.begin());
                cout << indice+1  << "\n";
            }
        }

    }



    return 0;
}