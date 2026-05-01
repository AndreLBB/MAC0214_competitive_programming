#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
#define ll long long
 
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll x,y,k;
    cin>>x>>y>>k;
    ll saltos = 0;
    if (x == 0 && y==0){
        cout<< 0<<"\n";
        continue;
    }
    ll saltos_em_x = 0;
    ll saltos_em_y = 0;

    saltos_em_x = x/k;
    if (x%k !=0){
        saltos_em_x++;
    }
    saltos_em_y = y/k;
    if (y%k !=0){
        saltos_em_y++;
    }
    if (saltos_em_x>saltos_em_y){
        saltos = 2*saltos_em_x -1;
    }
    else{
        saltos = 2*saltos_em_y;
    }
    cout<< saltos<<"\n";
}
 
return 0;
}
