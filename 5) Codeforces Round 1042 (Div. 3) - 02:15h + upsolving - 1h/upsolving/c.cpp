#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    ll t,n,k;
    cin>> t;
    for (int i= 0;i<t;i++){
        cin>> n;
        cin>>k;
        bool da = true;

        vector<ll> s(n);
        vector<ll> t(n);
        for(int j=0;j<n;j++){
            cin>> s[j];
            s[j] = min(s[j] % k, (k-s[j]%k)%k);
        }
        for(int j=0;j<n;j++){
            cin>>t[j];
            t[j] = min(t[j] % k, (k-t[j]%k)%k);
        }
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
        for(int j=0;j<n;j++){
            if (s[j]!=t[j]){
                da= false;
                break;
            }
        }

        if (da){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }   
    }
    return 0;
}