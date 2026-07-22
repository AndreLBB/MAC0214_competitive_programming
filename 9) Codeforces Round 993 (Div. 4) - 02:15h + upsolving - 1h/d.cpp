#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll t;
    cin>> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> resposta(n);
        vector<bool> apareceu(n + 1, false);

        for (int i = 0; i < n; i++) cin >> a[i];

        int livre = 1;

        for (int i = 0; i < n; i++) {
            if (!apareceu[a[i]]) {
                apareceu[a[i]] = true;
                resposta[i] = a[i];
            } else {
                while (apareceu[livre]){
                    livre++;
                }    
                apareceu[livre] = true;
                resposta[i] = livre;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << resposta[i];
        }
        cout << '\n';
    }

}