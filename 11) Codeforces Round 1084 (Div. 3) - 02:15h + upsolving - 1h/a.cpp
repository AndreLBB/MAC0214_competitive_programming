#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        for (int i = 0;i<n;i++) cin>>a[i];
        ll maior_valor = 0;
        for (int i = 0;i<n;i++){
            if (a[i]>maior_valor){
                maior_valor = a[i];
            }
        }
        ll count = 0;
        for (int i = 0;i<n;i++){
            if (a[i] == maior_valor){
                count++;
            }
        }
        cout <<count<<"\n";
    }

}
