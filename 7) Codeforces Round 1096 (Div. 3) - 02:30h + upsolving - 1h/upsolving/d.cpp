#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
#define ll long long

// fazer em O(n log n)
// procurar palindormos, achar o mex de cada e pegar o 
// menor? N sei nem achar palindromos de forma eficiente

// brute force seria encontrar um valor, busca o
// outro dele no array e avança com dois ponteiros pra
// dentro verificando se eh palindromo, isso eh O(n ^2)

// podesse ordenar um array que cada elemento eh uma dupla
// do elemento com sua posicao no array original e ai fazer
// busca binaria nesse array ao inves de varre pra encontrar
// o outro

// mas nao muda o problema de varrer de fora pra dentro
// que eh o que realmente da o(n^2)

// acredito que seja slidding window

// pra maximixar o mex, vc tem que encontrar a maior
// sequencia crescente partindo do zero 

// talvez encontrar o 0 e tentar crescer a janela a partir
// dele, e ai basta encontrar o maior palindromo a partir
// do 0, como tem dois zeros, talvez uma func pra crescer


// como calcular o mex dentro de um array que estou 
// expandindo

// o mex é apenas o maior inteiro que não está no array
// então basicamente vc mantem uma estrutura ordenada com
// todos os possíveis valores, isto é, 0 1 2 3 4 ...7
// depois varre o array e apaga dessa estrutura o valor do
// array e depois retorna o valor da frente da estrutura

int expande(int l, int r, vector<int> &a,int n){

    set<int> s;
    for (int i = 0;i<=n;i++){
        s.insert(i);
    }
    while (l>=0 && r<2*n && a[l]==a[r]){
        s.erase(a[l]);
        l--;
        r++;
    }
    return *s.begin();
}


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll n;
    cin>>n;
    ll pos_0_1 = -1;
    ll pos_0_2 = -1;
    vector<int> a(2*n);
    for (int j = 0;j<2*n;j++){
        cin>> a[j];
    }
    for (int j = 0;j<2*n;j++){
        if (a[j] == 0 && pos_0_1 ==-1){
            pos_0_1 = j;
        }
        else if (a[j] == 0 && pos_0_1 !=-1){
            pos_0_2 = j;
        }
    }
    ll meio_l = (pos_0_1 + pos_0_2) / 2;
    ll meio_r = (pos_0_1+pos_0_2+1)/2;
    int resposta = max(expande(pos_0_1, pos_0_1,a,n), expande(pos_0_2,pos_0_2,a,n));
    resposta = max(resposta, expande(meio_l,meio_r,a,n));
    cout<< resposta<< "\n";
}
 
return 0;
}
