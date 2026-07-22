#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){

    ll t;
    cin>>t;
    int valor_maximo = 1000000;
    vector<int> pre(valor_maximo + 1);
    for (int i = 2; i <= valor_maximo; i++) {
        pre[i] = i;
    }
    for (int i = 2; i * i <= valor_maximo; i++) {
        if (pre[i] == i) {
            for (int j = i * i; j <= valor_maximo; j += i) {
                if (pre[j] == j) {
                    pre[j] = i;
                }
            }
        }
    }


    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool esta_ordenado = true;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 && a[i] < a[i - 1]) {
                esta_ordenado = false;
            }
        }

        if (esta_ordenado) {
            cout << "Bob\n";
        }
        else{
            bool alice_vence_cedo = false;
            vector<int> bases(n);
            
            for (int i = 0; i < n; i++) {
                if (a[i] == 1) {
                    bases[i] = 0;
                } else {
                    int p = pre[a[i]];
                    bases[i] = p;
                    int temporario = a[i];
                    while (temporario % p == 0) {
                        temporario /= p;
                    }
                    if (temporario > 1) {
                        alice_vence_cedo = true;
                        break;
                    }
                }
            }

            if (alice_vence_cedo) {
                cout << "Alice\n";
            }
            else{
                bool bases_ordenadas = true;
                for (int i = 1; i < n; i++) {
                    if (bases[i] < bases[i - 1]) {
                        bases_ordenadas = false;
                        break;
                    }
                }

                if (!bases_ordenadas) cout << "Alice\n";
                else cout << "Bob\n";
            }
        }
    }
}
