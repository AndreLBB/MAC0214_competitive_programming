#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

// 2 4 1 0 -1
// -1 0 1 2 4 -> MEX = 3
// 0 1 2 3 5 -> MEX = 4
// -2 -1 0 1 2 



// 4


// -1 1 2 3 5 6 -> MEX = 0
// -1 0 1 2 4 -> MEX = 3

// MEX  = quantos elementos eu tenho em
// sequência antes de ter uma quebra , ou seja,
// |a[i-1] - a[i] |!= 1 começando do 0 

// Tamanho da maior sequência estritamente
//  crescente sem quebras quando ordenado e sem 
// sem considerar elementos repetidos




int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

ll n,l;
cin >> n;
for (ll i=0;i<n;i++){
    cin >> l;
    vector<ll> v(l);
    for (ll j = 0;j<l;j++){
        cin >> v[j];  
    }
    sort(v.begin(),v.end());
    ll maior = 1;
    ll maior_atual = 1;
    ll p1 = 0;
    for (ll p2 = 1;p2<l;p2++){
        if (abs(v[p2] - v[p1])> 1){
            p1 = p2;
            if (maior_atual> maior){
                maior = maior_atual;
            }
            maior_atual = 1;
            continue;
        }
        else if (abs(v[p2] - v[p1]) == 1){
            maior_atual++;
        }
        p1++;
    }
    if (maior_atual > maior){
        maior = maior_atual;
    }
    cout << maior<<"\n";
}
return 0;
}