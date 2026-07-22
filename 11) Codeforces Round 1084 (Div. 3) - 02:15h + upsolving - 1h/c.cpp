#include <bits/stdc++.h>
#define ll long long 
using namespace std;

// aaa******bbb
// aa********bb
int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        bool can = true;
        for (int i = 0;i<n/2;i++){
            for (int j = 1;j<n;j++){
                if (s[j]==s[j-1]){
                    s.erase(j-1,2);
                }
            }
        }
        if (s.size()>0) can = false;
        if (can){
            cout<<"YES"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }

}
