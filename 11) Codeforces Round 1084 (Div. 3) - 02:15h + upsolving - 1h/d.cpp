#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int x, y;
        cin >> x >> y;
        
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        vector<int> s;
        for (int i = 0; i < x; i++) s.push_back(p[i]);
        for (int i = y; i < n; i++) s.push_back(p[i]);

        vector<int> b;
        for (int i = x; i < y; i++) b.push_back(p[i]);

        int min_idx = 0;
        for (int i = 1; i < b.size(); i++) {
            if (b[i] < b[min_idx]) {
                min_idx = i;
            }
        }

        vector<int> B_min;
        for (int i = min_idx; i < b.size(); i++) B_min.push_back(b[i]);
        for (int i = 0; i < min_idx; i++) B_min.push_back(b[i]);
        int k = 0;
        while (k < s.size() && s[k] < B_min[0]) {
            k++;
        }
        for (int i = 0; i < k; i++) cout << s[i] << " ";
        for (int i = 0; i < B_min.size(); i++) cout << B_min[i] << " ";
        for (int i = k; i < s.size(); i++) cout << s[i] << " ";
        cout << "\n";
    }

}
