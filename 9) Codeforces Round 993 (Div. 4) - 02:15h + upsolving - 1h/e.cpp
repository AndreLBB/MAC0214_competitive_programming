#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll primeiro_valido(ll p, ll l1, ll r1, ll l2) {
    ll lo = l1, hi = r1;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        if (mid * p >= l2)
            hi = mid;
        else
            lo = mid + 1;
    }

    if (lo * p >= l2) return lo;
    return r1 + 1;
}

ll ultimo_valido(ll p, ll l1, ll r1, ll r2) {
    ll lo = l1, hi = r1;

    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;

        if (mid * p <= r2)
            lo = mid;
        else
            hi = mid - 1;
    }

    if (lo * p <= r2) return lo;
    return l1 - 1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        ll resposta = 0;
        ll potencia = 1;

        while (true) {
            ll L = primeiro_valido(potencia, l1, r1, l2);
            ll R = ultimo_valido(potencia, l1, r1, r2);

            if (L <= R)
                resposta += R - L + 1;

            if (potencia > r2 / k)
                break;

            potencia *= k;
        }

        cout << resposta << '\n';
    }

    return 0;
}