#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
#define ll long long

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

// Preciso fazer em O(n+m) pra cada caso
ll t,n,m,h;
cin >> t;
for (ll i=0;i<t;i++){
    cin >> n>>m>>h;

    vector<ll> a(n);
    for (ll j = 0;j<n;j++){
        cin >> a[j];  
    }
    vector<ll> copia = a;
    vector<ll> b(m);
    vector<ll> c(m);
    for (ll j = 0;j<m;j++){
        cin >> b[j];
        b[j]--;
        cin >> c[j];
    }
    vector<ll> reset(n);
    ll last_reset = -1;
    // Quando eu for somar c_i no a_i, eu 
    // olho se a ultima_vez que ele foi resetado
    // é igual ao ultimo reset que teve
    // se sim eu apenas somo c_i no a_i, se não
    // eu volto a_i pro valor original e somo c_i
    for (ll j = 0;j<m;j++){
        if (reset[b[j]] < last_reset){
            reset[b[j]] = last_reset;
            a[b[j]] = copia[b[j]];
        }
        if (a[b[j]]+c[j]>h){
            last_reset = j;
        }
        else{
            a[b[j]]=a[b[j]]+c[j];
        }
    }
    for (ll j = 0;j<n;j++){
        if (reset[j]<last_reset){
            a[j] = copia[j];
        } 
    } 
    for (ll j = 0;j<n;j++){
        cout << a[j] <<' ';  
    }
    cout<<"\n";

}
return 0;
}