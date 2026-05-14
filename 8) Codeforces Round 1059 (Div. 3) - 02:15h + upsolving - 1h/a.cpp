#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

int t; cin >> t;
while(t--){
    int n; cin >> n;
    vector<int> a(n);
    int maior = 1;
    for (int i=0;i<n;i++){
        cin>> a[i];
        if (a[i]>maior){
            maior = a[i];
        }
    }
    cout<< maior<<"\n";
}
return 0;
}