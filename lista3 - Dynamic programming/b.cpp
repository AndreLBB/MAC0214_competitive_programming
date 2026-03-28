#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    
    const ll m = 1e9 + 7;
    ll n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            cin>> grid[i][j];
        }
    }
    vector<vector<ll>> resposta(n+1, vector<ll>(n+1));
    if (grid[0][0] == '*'){
        cout << 0 <<"\n";
        return 0;
    }
    else{
        resposta[1][1] =1;
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            if (i==1 && j==1) continue;
            if (grid[i-1][j-1] == '*') resposta[i][j] = 0;
            else{
                resposta[i][j] = (resposta[i-1][j]+resposta[i][j-1])%m;
            }
        }
    }
    cout<<resposta[n][n]<<"\n";

    return 0;
}