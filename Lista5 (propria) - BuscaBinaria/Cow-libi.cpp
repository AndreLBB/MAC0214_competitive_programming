// https://usaco.org/index.php?page=viewproblem2&cpid=1303
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

// Seja B(x,y,t) o ponto de hálibe de uma vaca
// E A(x,y,t) o ponto de pasto com o maior t menor que t_B
// E C(x,y,t) o ponto de pasto com o menor t maior que t_B 
// A vaca é inocente se 
// dist(A,B) > t_B - t_A ou dist(B,C) > t_C - t_B
// ela é inocente se for impossível ela sair de um pasto
// ir pro halibe e ir pro proximo pasto

ll eh_possivel(pair<int, pair<int, int>> A, pair<int, pair<int, int>> B){
    ll x_a = A.second.first;  
    ll x_b = B.second.first;  
    
    ll y_a = A.second.second;  
    ll y_b = B.second.second;  

    ll t_a = A.first;
    ll t_b = B.first;

    return (x_b-x_a) * (x_b-x_a) + (y_b-y_a) * (y_b-y_a) <= (t_b - t_a) * (t_b - t_a); 
}

bool cmp(pair<int, pair<int,int>> A, pair<int, pair<int,int>> B){

    return A.first < B.first;
}


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int g,n;
    cin>>g>>n;
    vector<pair<int, pair<int,int>>> grazes(g);
    for (int i = 0; i<g;i++){
        cin >> grazes[i].second.first;
        cin >> grazes[i].second.second;
        cin >> grazes[i].first; // o t eh a chave
    }
    vector<pair<int, pair<int,int>>> halibes(n);
        for (int i = 0; i<n;i++){
        cin >> halibes[i].second.first;
        cin >> halibes[i].second.second;
        cin >> halibes[i].first; // o t eh a chave
    }
    int count = 0;
    sort(grazes.begin(),grazes.end());
    for (int i = 0;i<n;i++){
        int t_b = halibes[i].first;
        auto C = upper_bound(grazes.begin(),grazes.end(),halibes[i], cmp);

        if ( C != grazes.end() && !eh_possivel(halibes[i], *C)){
            count++;
        }

        else if (C != grazes.begin()){
            auto A = C -1;
            if (!eh_possivel(*A, halibes[i])){
                count++;
            }
        }

    }
    cout<< count<<"\n";

return 0;
}
