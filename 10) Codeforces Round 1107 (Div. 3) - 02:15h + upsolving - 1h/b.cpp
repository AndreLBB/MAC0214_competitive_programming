#include <bits/stdc++.h>
#define ll long long
using namespace std;

int numDigits(long long x) {
    if (x == 0) return 1;
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int main(){

    ll t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a = numDigits(n);
        ll y = 1;
        for (int i = 0; i < a; i++) {
            y *= 10;
        }
        y += 1;
        
        cout << y << "\n";
    }
}