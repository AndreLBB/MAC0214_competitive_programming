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
    ll x,y;
    cin>> x>>y;
    ll da = false;

    if (x%2==0 || y%2 ==0){
        da = true;
    }
    else if ((x%2==0) && (y%2 == 1) || (y%2==0) && (x%2 == 1)){
        da = true;
    } 
    if (da){
        cout<< "YES"<< "\n";
    }
    else{
        cout<< "NO"<<"\n";
    }
}
 
return 0;
}
