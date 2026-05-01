#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t,n;
cin >> t;
for (int i=0;i<t;i++){
    cin>> n;
    vector<char> s(n);
    vector<char> t(n);
    for (int j = 0;j<n;j++){
        cin>> s[j];
    }
    for (int j = 0;j<n;j++){
        cin>> t[j];
    }
    vector<int> ja(n,-1);
    int da = 1;
    int achei = 0;
    for (int j = 0;j<n;j++){
        for(int k = 0;k<n;k++){
            if (s[j]==t[k] && ja[k] == -1){
                ja[k] = 1;
                achei = 1;
                break;
            }
        }
        if (achei !=1){
            da = 0;
            break;
        }
        achei =0;
    }
    if (da == 1){
        cout<< "YES" << "\n";
    }
    else{
        cout<< "NO" << "\n";
    }
}

return 0;
}