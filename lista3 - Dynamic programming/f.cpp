#include <algorithm>
#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

    //max_pedacos_fita(l) = numero maximo de pedaços
    // pra uma fita de tamanho l
    //max_pedacos_fita(l) = max(max_pedacos_fita(l-a),max_pedacos_fita(l-b))
    // /max_pedacos_fita(l-c)) +1
    ll n,a,b,c;
    cin >> n>>a>>b>>c;
    vector<ll> max_pedacos_fita(n+1,-1);
    vector<ll> cortes(3);
    cortes[0] = a;
    cortes[1] = b;
    cortes[2] = c;
    max_pedacos_fita[0]=0;
    for (int i = 1;i<=n;i++){
        ll max_ = -1;
        for (auto corte: cortes){
            if (i-corte>=0){
                if (max_pedacos_fita[i-corte] ==-1) continue;
                else max_ = max(max_,max_pedacos_fita[i-corte]+1);
            }
        }
        max_pedacos_fita[i]=max_;
    }  
    cout<<max_pedacos_fita[n]<<"\n";
    return 0;
}