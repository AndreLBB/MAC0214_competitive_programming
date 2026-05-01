#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long
 
// da pra fazer em o(n^2)

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t, n;
cin >> t;
for (int i=0;i<t;i++){
    cin >> n;
    vector<ll> a(n);
    for (int j = 0;j<n;j++){
        cin >>a[j];
    }
    ll maior = 0;
    for (int j = 0;j<n;j++){
        for (int k = j;k<n;k++){
            if ((a[j]^a[k])>maior){
                maior = (a[j]^a[k]);
            }
        }
    }
    cout << maior<<"\n";
}
 
return 0;
}
