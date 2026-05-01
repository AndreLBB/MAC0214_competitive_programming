#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long
 

// Precisa fazer em O(n+m) = 0(n)
// pra cada inteiro i entre 1 e n ele pode ou não fazer
// uma op, que é setar a_i pra ser b_1(b[0]) - a_i

// quer saber se usando isso ele pode ordenar em
// ordem nao decrescente ou nao

// Basicamente a gente pode setar cada elemento de a
// pra ser b-a ou não e devemos saber se com isso
// o array fica ordenado ou não

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    ll b;
    int da = 1;
    for (int j =0;j<n;j++){
        cin>> a[j];
    }
    cin>>b;

    ll r = 1;
    ll l = 0;
    a[0] = min(a[0], b - a[0]);
    while (r<(ll)a.size()){
        ll menor = min(b-a[r],a[r]);
        if (menor>=a[l]){
            a[r] = menor;
        }


        else if(max(b-a[r],a[r])>=a[l]){
            a[r] = max(b-a[r],a[r]);;
        }
        else{
            da=0;
            break;
        }
        l++;
        r++;
    }
    if (da == 0){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
    }
}
 
return 0;
}