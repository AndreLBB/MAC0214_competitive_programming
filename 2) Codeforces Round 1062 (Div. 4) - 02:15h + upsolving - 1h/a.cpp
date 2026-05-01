#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    vector<ll> v(4);
    for (int j = 0;j<4;j++){
        cin>>v[j];
    }
    if ((v[0] == v[1])&& (v[1]==v[2]) && (v[2]==v[3])){
        cout << "YES"<< "\n";
    }
    else{
        cout << "NO"<< "\n";
    }
}

return 0;
}