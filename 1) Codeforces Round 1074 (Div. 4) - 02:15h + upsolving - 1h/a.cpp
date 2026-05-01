#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

int n,c;
cin >> n;
for (int i=0;i<n;i++){
    cin >> c;
    for (int j =1;j<=c;j++){
        cout << j << " ";
    }
    cout << "\n";
}
return 0;
}