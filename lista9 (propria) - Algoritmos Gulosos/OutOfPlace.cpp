// https://usaco.org/index.php?page=viewproblem2&cpid=785
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    ll n;
    cin>> n;
    vector<ll> h(n);
    for (int i = 0;i<n;i++){
        cin>>h[i];
    }
    vector<ll> copia = h; 
    sort(copia.begin(), copia.end());
    ll foras = 0;
    for (int i = 0;i<n;i++){
        if (copia[i]!= h[i]){
            foras++;
        }
    }
    cout <<foras-1<<endl;
}