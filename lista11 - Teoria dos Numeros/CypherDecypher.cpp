// https://codeforces.com/gym/103274/problem/C
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


int main() {

    int pior_caso = 1000000;
    vector<bool> isprime(pior_caso + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    // grande crivo
    for (ll p = 2; p * p <= pior_caso; p++){
        if (isprime[p]){
            for (ll i = p * p; i <= pior_caso; i += p){
                isprime[i] = false;
            }
        }
    }
    // precomputa para as queries
    vector<ll> prefix_sum(pior_caso + 1);
    for (int k = 0;k<=pior_caso;k++){
        if (k == 0){
            prefix_sum[k] = 0;
        }
        else{
            prefix_sum[k] = prefix_sum[k-1] + isprime[k];
        }
    }

    ll t,i,j;
    cin >> t;
    for (ll c = 0; c<t;c++){
        cin >> i >> j;
        cout << prefix_sum[j] - prefix_sum[i-1] << "\n";
    }



    return 0;
}