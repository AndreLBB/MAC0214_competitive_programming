// https://usaco.org/index.php?page=viewproblem2&cpid=573
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    ll n;
    ll pontos = 0;
    cin >> n;
    
    vector<ll> elsie_cards(n);
    unordered_set<ll> s;
    for (int i = 0; i < n; i++){
        cin >> elsie_cards[i];
        s.insert(elsie_cards[i]);
    }
    
    vector<ll> bessie(n);
    ll j = 0;
    for (int i = 1; i <= 2 * n; i++){
        if (s.find(i) == s.end()){
            bessie[j] = i;
            j++;
        }
    }

    vector<ll> elsie1, elsie2;
    for (int i = 0; i < n / 2; i++) {
        elsie1.push_back(elsie_cards[i]);
    }
    for (int i = n / 2; i < n; i++) {
        elsie2.push_back(elsie_cards[i]);
    }

    vector<ll> bessieC, bessieD; 

    for (int i = n - 1; i >= n / 2; i--) {
        bessieC.push_back(bessie[i]);
    }
    for (int i = 0; i < n / 2; i++) {
        bessieD.push_back(bessie[i]); 
    }
    sort(elsie1.begin(), elsie1.end(), greater<ll>());
    sort(elsie2.begin(), elsie2.end());

    j = 0;
    for (int i = 0; i < n / 2; i++){
        if (bessieC[j] > elsie1[i]){
            j++;
            pontos++;
        }
    }
    j = 0;
    for (int i = 0; i < n / 2; i++){
        if (bessieD[j] < elsie2[i]){
            j++;
            pontos++;
        }
    }

    cout << pontos << "\n";
    return 0;
}