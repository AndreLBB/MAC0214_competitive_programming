// https://codeforces.com/gym/102644/problem/C
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m = 1e9+7;

vector<vector<ll>> multiplica(vector<vector<ll>> A, vector<vector<ll>> B) {
    vector<vector<ll>> matriz_multiplicada(2, vector<ll>(2, 0));
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                matriz_multiplicada[i][j] = (matriz_multiplicada[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return matriz_multiplicada;
}

vector<vector<ll>> exponenciacao_matriz(vector<vector<ll>> matriz_base, ll n) {
    vector<vector<ll>> matriz_identidade = {{1, 0}, {0, 1}};
    
    while (n > 0) {
        if (n % 2 != 0) {
            matriz_identidade = multiplica(matriz_identidade, matriz_base);
        }
        matriz_base = multiplica(matriz_base, matriz_base);
        n = n / 2;
    }
    
    return matriz_identidade;
}

int main(){
    ll n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<vector<ll>> matriz_fibonacci = {{1, 1}, {1, 0}};
    vector<vector<ll>> matriz_final = exponenciacao_matriz(matriz_fibonacci, n);
    
    cout << matriz_final[0][1] << "\n";
    
    return 0;
}