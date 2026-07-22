#include <bits/stdc++.h>
#define ll long long 
using namespace std;

// jogo acaba quando temos a_i < a_j com i>j obs aj ai
// to achando que vai ser 1 ou o numero de elementos no array
// se o array for já nao decresente
int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        for (int i = 0;i<n;i++) cin>>a[i];
        bool esta_nao_decrescente = true;
        ll r = 0;
        while (r<n-1){
            if (a[r]>a[r+1]){
                esta_nao_decrescente = false;
            }
            r++;
        }
        if (esta_nao_decrescente){
            cout<<n<<"\n";
        }
        else cout<<"1"<<"\n";
    }

}
