#include <bits/stdc++.h> 
#include <deque>
#include <iostream>
#include <utility>
#include <vector>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

    ll t;
    cin >> t; 

    for (ll k = 0; k<t;k++){
        ll n;
        cin >> n;
        vector<ll> h(n);
        deque<pair<ll, ll>> pilha;
        vector<ll> l(n);
        pilha.push_back({-1,0});
        for (ll i = 0;i< n;i++){
            cin>> h[i];

        }
        for (ll i=0;i<n;i++){
            while (h[i] <= pilha.back().second){
                pilha.pop_back();
            }
            l[i] = pilha.back().first;
            pilha.push_back({i,h[i]});
        }

        deque<pair<ll,ll>> pilha2;
        vector<ll> r(n);
        pilha2.push_back({n,0});
        for (ll j=n-1;j>=0;j--){
            while (h[j] <= pilha2.back().second){
                pilha2.pop_back();
            }
            r[j] = pilha2.back().first;
            pilha2.push_back({j,h[j]});
        }
        vector<ll> areas;
        ll maior_area = 0;
        ll area_atual= 0;
        for (ll i = 0;i<n;i++){
            area_atual = (r[i] - l[i] -1) * h[i];       
            if (area_atual > maior_area){
                maior_area = area_atual;
            }
        }        
        cout << "Case "<<k+1<<": "<< maior_area << "\n";
    }

    return 0;
}