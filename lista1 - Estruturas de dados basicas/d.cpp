#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

ll ns, dias;
cin >> ns;
vector<ll> preco(ns);
for (ll i = 0;i<ns;i++){
    cin >>preco[i]; 
}
sort(preco.begin(), preco.end());

cin >> dias;
for (ll i =0;i<dias;i++){
    ll moedas;
    cin >> moedas;
    auto it = upper_bound(preco.begin(), preco.end(), moedas);
    if(it == preco.begin()){
        cout << 0 << "\n";
    }
    else{
        cout << it - preco.begin() << "\n"; // esse it - preco.begin() eh basicamente
        // ponteiro maluco pro meio do vetor - ponteiro maluco pro inicio e por aritmetica
        // normal(?) isso da o numero de elementos
    }
}
return 0;
}