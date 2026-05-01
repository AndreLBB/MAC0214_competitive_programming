#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t,n;
cin >> t;
vector<int> x = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
for (int i=0;i<t;i++){

    cin >> n;
    vector<ll> v(n);
    for (int j = 0;j<n;j++){
        cin>>v[j];
    }
    int qual = -1;
    for (int k : x){
        for (ll a_i: v){
            if (a_i % k != 0){
                qual = k;
                break;
            }
        }
        if (qual != -1){
            break;
        }
    }
    cout<<qual<<"\n";

}
return 0;
}