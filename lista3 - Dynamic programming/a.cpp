#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    
    const ll m = 1e9 + 7;
    ll n,x;
    cin>> n>> x;
    vector<ll> c_i(n);
    for (int i=0;i<n;i++){
        cin>> c_i[i]; 
    }
    vector<ll> sum(x+1);
    sum[0] = 1;
    for (int i = 1;i<=x;i++){
        for (auto c : c_i){
            if (i-c>=0){
                sum[i] = (sum[i] + sum[i-c])%m;
            }
        }
    }
    cout<< sum[x]<<"\n";
    return 0;
}