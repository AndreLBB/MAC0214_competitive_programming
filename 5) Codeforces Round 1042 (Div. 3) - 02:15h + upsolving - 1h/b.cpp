#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long

// tem que ser O(n)
// pra negativos podemos so usar o -1
// pra positivos

// -1 2 -1 3

// -1 2 -1 
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    ll t,n;
    cin>> t;
    for (int i= 0;i<t;i++){
        cin>> n;
        if (n==2){
            cout << "-1 2"<<"\n";
            continue;
        }
        ll valor = 3;
        for (int j = 0;j<n;j++){
            if (n%2 == 0 && j == n-1){
                cout<<2<<" ";
                continue;
            }
            if (j%2 ==0){
                cout<<-1<<" ";
            }
            else{
                cout<<valor<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}