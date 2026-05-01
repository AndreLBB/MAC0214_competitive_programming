#include <bits/stdc++.h> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std; 
#define ll long long
 
// fazer em O(n)

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    ll n;
    cin>>n;
    string s;
    cin>> s;
    bool da = false;
    ll count1 = 0;
    ll count2 = 0;
    for (int j = 0;j<n;j++){
        if (s[j]=='('){
            count1++;
        }
        else{
            count2++;
        }
    }
    if (count1 == count2){
        da=true;
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
