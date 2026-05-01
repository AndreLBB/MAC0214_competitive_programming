#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long
 


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t, x;
cin >> t;
for (int i=0;i<t;i++){
    cin >> x;
    if (x == 67){
        cout << 67<<"\n";
        continue;
    }
    cout << x+1<<"\n";
}
 
return 0;
}
