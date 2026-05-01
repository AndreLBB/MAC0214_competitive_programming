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

    cin >> n;
    vector<ll> v(n);
    int tem_par = 0;
    int tem_impar = 0;
    for (int j = 0;j<n;j++){
        cin>>v[j];
        if (v[j] %2 == 0){
            tem_par = 1;
        }
        else{
            tem_impar = 1;
        }
    }
    if (tem_par+tem_impar == 2){
        sort(v.begin(),v.end());
    }
    for (int j = 0;j<n;j++){
        cout<< v[j] << " ";
    }
    cout<<"\n";
    
}
return 0;
}