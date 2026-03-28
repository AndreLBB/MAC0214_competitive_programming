#include <algorithm>
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> lcs(n+1, vector<ll>(m+1));
    vector<ll> p;
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i = 0;i<n;i++){
        cin>> a[i];
    }
    for(int j = 0;j<m;j++){
        cin>>b[j];
    }
    for (int i = n-1;i>=0;i--){
        for (int j = m-1;j>=0;j--){
            if (a[i] == b[j]){
                lcs[i][j] = lcs[i+1][j+1]+1;
            }
            else{
                lcs[i][j] = max(lcs[i+1][j],lcs[i][j+1]);
            }

        }
    }
    cout<<lcs[0][0]<<"\n";
    ll i = 0;
    ll j=0;
    while (i<n && j<m){
        if (a[i] == b[j]){
            cout << a[i] <<" ";
            i++;
            j++;
        }
        else{
            if (lcs[i+1][j]>lcs[i][j+1]){
                i++;
            }
            else{
                j++;
            }
        }
    }
    cout<<"\n";
    return 0;
}