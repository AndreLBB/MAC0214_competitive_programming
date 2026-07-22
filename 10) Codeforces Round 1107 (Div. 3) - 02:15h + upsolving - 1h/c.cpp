#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int transicoes = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                transicoes++;
            }
        }
        if (transicoes == 1) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    
    return 0;
}