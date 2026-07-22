#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll t;
    cin>> t;

    while(t--){
        ll m,a,b,c;
        cin>>m>>a>>b>>c;
        ll n = 0;
        ll resto_a = 0;
        ll resto_b = 0;
        if (a>m) n += m;
        else {
            n+= a;
            resto_a = m-a;
        }
        if (b>m) n+=m;
        else{
            n +=b;
            resto_b = m-b;
        }
        if (resto_a >0 || resto_b>0){
            if (c > (resto_a + resto_b)) n += (resto_a + resto_b);
            else n+=c;
        }

        cout<<n<<"\n";
    }

}