#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
#define ll long long
 
// 1 2 3 4 5 6 7 8 9
// 1 8 9
// 2 6 7
// 3 4 5
// 

//O que vc quer é: Os dois maiores num trio, 
// depois os próximos 2 maiores num trio e assim vai n vezes
// O número restante em cada um desses trios, pode
// ser qualquer número restante

// 2 3n-3  3n-2  1 3n-1 3n

// 3n 3n-2 3n-4
// 3n -1, 3n-3, 3n-5
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);
int t,n;
cin >> t;
ll p = 0;
for (int i=0;i<t;i++){
    cin>> n;
    vector<ll> a(3*n);
    for (int j = 0;j<3*n;j=j+3){
        a[j] = p+1;
        a[j+1] = (3*n - 1) - 2*p;
        a[j+2] = 3*n - 2*p;
        p++;
    }
    for (int j = 0;j<3*n;j++){
        cout << a[j]<<" ";
    }
    cout<<"\n";
    p = 0;
}
return 0;
}