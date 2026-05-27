// https://usaco.org/index.php?page=viewproblem2&cpid=643
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> tamanho_comeca_i(n);
    vector<ll> maior_tamanho_apos_i(n+1); // parecido com o LCS
    // esses acima sao disjuntos
    int p1 =0,p2 = 1;
    while (p1<n){
        while(p2<n && a[p2]-a[p1]<=k) p2++;
        tamanho_comeca_i[p1] = p2-p1;
        p1++;
    }
    maior_tamanho_apos_i[n] = 0;
    for (int i = n-1;i>=0;i--){
        maior_tamanho_apos_i[i] = max(maior_tamanho_apos_i[i+1], tamanho_comeca_i[i]);
    }
    int resposta = 0;
    for (int i = 0;i<n;i++){
        resposta = max((int)resposta,(int)(tamanho_comeca_i[i]+ maior_tamanho_apos_i[i+tamanho_comeca_i[i]]));
    }
    cout<<resposta;
return 0;
}
