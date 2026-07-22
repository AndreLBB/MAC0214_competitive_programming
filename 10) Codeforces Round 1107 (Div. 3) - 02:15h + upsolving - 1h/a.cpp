#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        bool can;
        if (y>x){
            can = false;
        }
        else if (x == y) can = true;
        else{
            if (x % y == 0) can = true;
            else can = false;
        }
        if (can) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

}