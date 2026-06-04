// https://cses.fi/problemset/task/1074
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll> p(n);
    for (int i = 0;i<n;i++){
        cin>> p[i];
    }
    sort(p.begin(), p.end());
    ll base = p[p.size()/2];
    ll total = 0;
    for (int i = 0;i<n;i++){
        total += abs(p[i]-base);
    }
    cout<<total<<"\n";
}