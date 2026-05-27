// https://cses.fi/problemset/task/1641
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> a(n);
    for (int i = 0;i<n;i++){
        cin>> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    int p1=0,p2=n-2,p3=n-1;
    while (p3>=2){
        while (p1<p2){
            int soma = a[p1].first+a[p2].first+a[p3].first;
            if (soma<x){
                p1++;
            }
            else if (soma > x){
                p2--;
            }
            else{
                cout << a[p1].second+1<<" "<< a[p2].second+1<<" "<<a[p3].second+1;
                return 0;

            }
        }
        // restart
        p2 = p3-2;
        p3--;
        p1 = 0;
    }
    cout<<"IMPOSSIBLE";
return 0;
}
