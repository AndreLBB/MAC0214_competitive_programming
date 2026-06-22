// https://codeforces.com/problemset/problem/300/C
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// basicamente precisamos saber quantos numeros 
// que tem o formato abaabbaba... tem soma igual
// dos digitos gerando um numero que tem o formato
// ababababaabbb

ll m = 1e9+7;


#include <iostream>

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

int main(){

    ll a, b, n;
    cin>>a>>b>>n;
    ll total = 0;
    ll n_max = 1e6;
    vector<ll> fac(n_max+1);
    vector<ll> inv(n_max+1);
	fac[0] = 1;
	for (ll i = 1; i <= n_max; i++) fac[i] = fac[i - 1] * i % m; 
	inv[n_max] = exp_rapida(fac[n_max], m - 2, m);
	for (ll i = n_max; i >= 1; i--) inv[i - 1] = inv[i] * i % m; 
    for (int i=0;i<=n;i++){ // i vai ser o numero de a no numero

        ll num = i * a + (n-i)*b;
        // preciso varrer um numero digito a digito
        bool eh_excelente = true;
        while (num != 0){
            int digito = num %10;
            if (!(digito == a || digito == b)){
                eh_excelente = false;
            }
            num /=10;
        }
        if (eh_excelente){
            ll num_comb = ((fac[n] * inv[i]) % m * inv[n-i]) % m;
            total = (total+ num_comb) %m;
        }
    }
    cout<<total<<"\n";


}