// https://cses.fi/problemset/task/1079
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll exp_rapida(ll base, ll expoente, ll m) {
	base %= m;
	ll resultado = 1;
	while (expoente > 0) {
		if (expoente % 2 == 1) { resultado = resultado * base % m; }
		base = base * base % m;
		expoente /= 2;
	}
	return resultado;
}

int main() {

    ll n_max = 1e6+1;
    ll m = 1e9 + 7;
    vector<ll> fac(n_max);
    vector<ll> inv(n_max);
	fac[0] = 1;
	for (ll i = 1; i <= n_max; i++) fac[i] = fac[i - 1] * i % m; 
	inv[n_max] = exp_rapida(fac[n_max], m - 2, m);
	for (ll i = n_max; i >= 1; i--) inv[i - 1] = inv[i] * i % m; 

	ll expoente;
    ll a, b;
	cin >> expoente;
	for (ll i = 0; i < expoente; i++) {
		cin >> a >> b;
		cout << fac[a] * inv[b] % m * inv[a - b] % m << '\n';
	}
}