#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long
 
// da pra fazer em quase O(n^2)

// truque de gcd() eh quebrar o numero em suas componentes
// montar uma seq que o gcd entre dois vai aumentando de
// um em um

// Assim:
// 1*3*5
// 1*5*7
// 1*7*9
// 1*9*11

// Parece que nao da pra seguir essa ideia do gcd ir 
// aumentando de 1 em 1, e se ignorarmos o 2 como coef pq
// ele ta dando merda
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t, n;
cin >> t;
for (int i=0;i<t;i++){
    cin >> n;
    ll o = 3;
    ll p =5;
    for (int j = 1;j<=n;j++){
        ll x = 1;
        x *= o * p;
        o+=2;
        p+=2;
        cout <<x<< " ";
    }
    cout << "\n";
}
 
return 0;
}
