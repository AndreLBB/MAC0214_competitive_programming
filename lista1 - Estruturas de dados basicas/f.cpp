#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
    ll k,n;
    cin >> k;
    string a;
    for (ll i = 0;i<k;i++){
        set<string> strings;
        cin >> n;
        vector<string> b(n);
        for (ll j = 0;j<n;j++){
            cin >> a;
            b[j] = a;
            strings.insert(a);
        }
        string saida;
        for (ll j = 0;j<n;j++){
            int encontrei = 0;
            for (ll w = 1; w< (ll)b[j].length();w++){
                auto it = strings.find(b[j].substr(0,w));
                auto it2 = strings.find(b[j].substr(w,b[j].length()-w));
                if (it != strings.end() && it2 != strings.end()){
                    encontrei = 1;
                }

            }
            if (encontrei == 1){
                saida.push_back('1');
            }
            else{
                saida.push_back('0');
            }
        }
        cout<<saida <<"\n";

    } 
    
    return 0;
}