#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> a(n);
    ll soma_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        soma_a += a[i];
    }

    vector<ll> b(m);
    ll soma_b = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        soma_b += b[i];
    }

    vector<ll> possiveis_A;
    for (int i = 0; i < n; i++) {
        possiveis_A.push_back(soma_a - a[i]);
    }
    sort(possiveis_A.begin(), possiveis_A.end());

    vector<ll> possiveis_B;
    for (int i = 0; i < m; i++) {
        possiveis_B.push_back(soma_b - b[i]);
    }
    sort(possiveis_B.begin(), possiveis_B.end());

    while (q--) {
        ll x;
        cin >> x;

        bool possivel = false;
        ll abs_x = abs(x);

        for (ll d = 1; d * d <= abs_x; d++) {
            if (abs_x % d == 0) {
                ll d1 = d;
                ll d2 = abs_x / d;
                
                if (x < 0) d2 = -d2;

                bool c1 = binary_search(possiveis_A.begin(), possiveis_A.end(), d1) && binary_search(possiveis_B.begin(), possiveis_B.end(), d2);
                bool c2 = binary_search(possiveis_A.begin(), possiveis_A.end(), -d1) &&  binary_search(possiveis_B.begin(), possiveis_B.end(), -d2);
                bool c3 = binary_search(possiveis_A.begin(), possiveis_A.end(), d2) && binary_search(possiveis_B.begin(), possiveis_B.end(), d1);
                bool c4 = binary_search(possiveis_A.begin(), possiveis_A.end(), -d2) && binary_search(possiveis_B.begin(), possiveis_B.end(), -d1);

                if (c1 || c2 || c3 || c4) {
                    possivel = true;
                    break;
                }
            }
        }

        if (possivel) cout << "YES\n";
        else cout << "NO\n";
        
    }
}