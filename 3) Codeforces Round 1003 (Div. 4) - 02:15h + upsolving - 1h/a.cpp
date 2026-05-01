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
    string a,b;
    cin>>a;
    b = a.substr(0,a.size()-2) +"i";
    cout<<b<<"\n";

}

return 0;
}