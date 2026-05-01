#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
#define ll long long
 
// fazer O(n) ou O(nlogn)


// como são distintos par a par basta ordenar x, varrer 
// procurando se dois consecutivos sao iguais
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll n;
    cin>>n;
    vector<ll> x(n);
    vector<ll> y(n);
    for (int j = 0;j<n;j++){
        cin>>x[j];
        cin>>y[j];
    }
    vector<ll> x_copy = x;
    ll resposta=0;
    sort(x_copy.begin(),x_copy.end());
    for (int j = 0;j<n-1;j++){
        if (x_copy[j]==x_copy[j+1]){
            resposta +=n-2;
        }
    }
    set<pair<int,int>> s;
    for (int j = 0;j<n;j++){
        s.insert({x[j],y[j]});
    }
    for (auto [x,y] : s){
        if (s.find({x-1,y^1}) !=  s.end() && s.find({x+1,y^1}) !=  s.end()){
            resposta++;
        }
    }
    cout<<resposta<<"\n";
}
 
return 0;
}
