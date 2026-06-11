// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll m = 1e9+7;
    ll n;
    cin>>n;
    vector<ll> num(n+1,0);
    vector<int> valores = {1,2,3,4,5,6};
    num[0] = 1;
    for (ll i = 0;i<=n;i++){
        for (int val : valores){
            if (i-val>=0){
                num[i] += num[i-val];
            }
        }
        num[i] = num[i] % m;
    }
    cout<<num[n]<<"\n";
}
