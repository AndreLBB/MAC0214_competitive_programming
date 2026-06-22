// https://codeforces.com/problemset/problem/1081/C
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll fac(ll x, ll m){
    vector<ll> fatorial(x+1);
    fatorial[0] = 1;
    for (int i = 1;i<=x;i++){
        fatorial[i] = i* fatorial[i-1] %m;
    }
    return fatorial[x];
}

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

ll inv(ll x, ll m){
    return exp_rapida(x,m-2,m) %m;
}

int main(){

    ll n,m,k;
    cin>>n>>m>>k;

    ll m_ = 998244353;
    ll comb = (fac(n-1, m_) * inv(fac(k,m_),m_)) %m_ * inv(fac(n-1-k,m_),m_) % m_;
    ll cores = (m* exp_rapida(m-1,k, m_)) %m_;
    ll resposta = comb * cores %m_;
    cout<< resposta<<"\n";
}