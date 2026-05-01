#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long

// da pra fazer O(n^2) se pa
// cond parada, pra qualquer i, a_i <= b_i

// posso sempre tirar do da esquerda e por no da direita
// como sei quando para? Ordenando?

//1 1 4 5 1 4
//1 9 1 9 8 1

// 1 1 1 4 4 5
// 1 1 1 8 9 9

// Ordenar não da pq percorre a ref do indice

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    ll t,n;
    cin>> t;
    for (int i= 0;i<t;i++){
            ll num = 1;
        cin>>n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int j = 0;j<n;j++){
            cin>> a[j];
        }
        for (int j = 0;j<n;j++){
            cin>> b[j];
        }
        for (int j = 0;j<n-1;j++){
            while (a[j]> b[j]){
                a[j] -=1;
                ll k =j;
                while(k+1<n && a[k+1]>=b[k+1]){
                    k++;
                }
                if (k+1<n) a[k+1]++;
                num++;
            }
        }
        while (a[n-1]>b[n-1]){
            a[n-1] -=1;
            num++;
        }
        cout<<num<<"\n";
    }
    return 0;
}