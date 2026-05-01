#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
#define ll long long
 
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll n;
    cin>>n;
    stack<ll> b;
    vector<vector<char>> map(n, vector<char>(4));
    for (int j = 0;j<n;j++){
        for (int k = 0;k<4;k++){
            cin>> map[j][k];
            if (map[j][k] == '#'){
                b.push(k+1);
            }
        }
    }
    for (int j = 0;j<n;j++){
        ll x = b.top();
        b.pop();
        cout<<x<<" ";
    }
    cout<<"\n";
}
 
return 0;
}
