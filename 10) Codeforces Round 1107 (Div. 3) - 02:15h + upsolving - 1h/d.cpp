#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    
    int t;
    cin>>t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        bool possivel = true;
        ll soma_prefixo = 0;
        
        for (int i = 0; i < n; i++) {
            ll b;
            cin >> b;
            
            ll diff = b - a[i];
            
            soma_prefixo += diff;
            
            if (soma_prefixo < 0) {
                possivel = false;
            }
        }
        
        if (possivel) cout << "YES\n";
        else cout << "NO\n";
    }
    
}