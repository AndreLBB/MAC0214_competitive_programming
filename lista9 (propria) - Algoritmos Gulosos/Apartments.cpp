// https://cses.fi/problemset/task/1084
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    for (int i = 0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> b(m);
    for (int i = 0;i<m;i++){
        cin>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll count = 0;
    ll p1 = 0; ll p2 = 0;
    while (p1<n && p2<m){

        if (b[p2]< a[p1]-k){
            p2++;
        }
        else if (b[p2]> a[p1]+k){
            p1++;
        }
        else {
            count++;
            p1++;
            p2++;
        }
    }

    cout<< count<<"\n";

}