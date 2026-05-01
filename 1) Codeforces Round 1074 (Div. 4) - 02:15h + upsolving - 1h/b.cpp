#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

int n,l;
cin >> n;
for (int i=0;i<n;i++){
    cin >> l;
    vector<ll> v(l);
    int maior = 0;
    for (int j = 0;j<l;j++){
        cin >> v[j];  
        if (v[j]> maior){
            maior = v[j];
        }
    }
    cout << maior *l << "\n";
}
return 0;
}