#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long
 


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    vector<ll> a(7);
    ll maior = -68;
    ll index_maior = -1;
    ll soma = 0;
    for (int i =0;i<7;i++){
        cin>> a[i];
        if (a[i]> maior){
            maior = a[i];
            index_maior = i;
        }
    }
    for (int i =0;i<7;i++){
        if (i !=index_maior){
            a[i] *= -1;
        }
        soma += a[i];
    }
    cout << soma<<"\n";
}
 
return 0;
}
