#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 
#define ll long long
 
 
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t;
cin >> t;
for (int i=0;i<t;i++){
    string a;
    cin>>a;
    int tem_par = 0;
    int l = 0;
    int r = 1;
    while (r<(ll)a.size()){
        if(a[r] == a[l]){
            r +=2;
            l+=2;
            tem_par = 1;
        }
        else{
            r++;
            l++;
        }
    }
    if (tem_par == 1){
        cout<<"1"<<"\n";
    }
    else{
        cout<<a.size()<<"\n";
    }
 
}
 
return 0;
}