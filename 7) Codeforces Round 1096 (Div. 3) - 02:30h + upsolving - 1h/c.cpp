#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
#define ll long long

// fazer em O(n log n)

// vc quer deixar os mult de 6 longe do restante
// quer deixar multi por 2 e por 3 longe um dos outros
// mas e os nao multi por 2 e 3 ? Nao eh ideial
// deixar eles no meio das coisas pra atrapalhar? 
// to sentindo que ta muito interativo

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> par;
    vector<ll> impar_nao_div_3;
    vector<ll> div_3;
    vector<ll> div_6;
    for (int j = 0;j<n;j++){
        cin>> a[j];
        if (a[j]%2==0 && (a[j]%6 != 0)){
            par.push_back(a[j]);
        }
        else if ((a[j]%3 != 0) && (a[j]%6 != 0)){
            impar_nao_div_3.push_back(a[j]);
        }
        else if ((a[j]%6 != 0)){
            div_3.push_back(a[j]);
        }
        else{
            div_6.push_back(a[j]);
        }
    }
    for (ll a : div_6){
        cout<<a<<" ";
    }
    for (ll a : par){
        cout<<a<<" ";
    }
    for (ll a : impar_nao_div_3){
        cout<<a<<" ";
    }
    for (ll a : div_3){
        cout<<a<<" ";
    }
    cout<< "\n";
}
 
return 0;
}
