#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

int n;
cin >> n;
vector<int> a(n);
for (ll i = 0;i<n;i++){
    cin >> a[i];
}
sort(a.begin(),a.end());

int iguais = 1;
int pares = 0;
for (ll i = 1;i<n;i++){
    if (a[i-1] == a[i]){
        iguais++;
    }
    else{
        int resto = iguais % 2;
        if (resto!=0){
            int resto2 = iguais - resto ;
            pares = pares + resto2 / 2;
        } 
        else{
            pares = pares + iguais/2;
        }
        iguais = 1;
    }
}
if (a[n-2] == a[n-1]){
    int resto = iguais % 2;
    if (resto!=0){
        int resto2 = iguais - resto ;
        pares = pares + resto2 / 2;
    } 
    else{
        pares = pares + iguais/2;
    }
}
cout << pares << "\n";
return 0;
}