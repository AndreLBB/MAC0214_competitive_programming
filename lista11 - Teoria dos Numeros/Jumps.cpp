// https://codeforces.com/gym/101341/problem/D
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


ll mdc(ll a, ll b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

int main(){

    ll n,x;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i< n;i++){
        cin >> v[i];
    }
    ll g = v[0];
    for (ll i = 1; i<n;i++){
        g = mdc(g, v[i]);
    }
    if (x%g==0){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}