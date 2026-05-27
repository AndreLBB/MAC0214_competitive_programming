// https://codeforces.com/contest/1201/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
    ll n,k;
    cin>> n>>k;
    vector<ll> a(n);
    for (int i = 0;i<n;i++) cin>> a[i];

    sort(a.begin(),a.end());
    int mid = (a.size()/2);

    vector<pair<ll, ll>> diff(a.size()/2);
    int multiplicador = 1;
    for (int i = 0;i<(int)diff.size();i++){
        diff[i].first = (a[mid+1+i] - a[mid+i])*multiplicador;
        multiplicador++;
        diff[i].second = (a[mid+1+i] - a[mid+i]);
    }
    int indice = -1;

    while (indice<(int)diff.size()-1 && k>= diff[indice+1].first){
        k = k - diff[indice+1].first;
        indice++;
    }
    if (indice<0){
        cout<<a[mid]+k<<"\n";
    }
    else{
        int quanti_iguais = indice+2;
        while(indice>=0){
            a[mid] += diff[indice].second;
            indice--;
        }
        cout<<a[mid]+k/quanti_iguais<<"\n";
    }

}
