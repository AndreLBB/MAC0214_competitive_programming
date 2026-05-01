#include <algorithm>
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long
 
// b_i -a_i >=a_i-1
//b_i >= a_i-1 - a_i

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(m);
    int da = 1;
    for (int j =0;j<n;j++){
        cin>> a[j];
    }
    for (int j =0;j<m;j++){
        cin>> b[j];
    }
    sort(b.begin(),b.end());
    // comparar o a[0] com o menor b[i] - a[0] >= a[0]
    a[0] = min(a[0], b[0] - a[0]);
    ll r = 1;
    ll l = 0;
    while (r<(ll)a.size()){
        auto y = lower_bound(b.begin(),b.end(),a[l]+a[r]);
        if (y !=b.end()){
            ll menor = min(a[r], *y-a[r]);
            ll maior = max(a[r], *y-a[r]);
            if (menor>= a[l]){
                a[r] = menor;
            }
            else{
                if (maior>=a[l]){
                    a[r] = maior;
                }
                else{
                    da =0;
                }
            }
        }
        else{
            if (a[r]<a[l]){
                da = 0;
            }
        }
        l++;
        r++;
    }
    if (da == 0){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
    }
}
 
return 0;
}