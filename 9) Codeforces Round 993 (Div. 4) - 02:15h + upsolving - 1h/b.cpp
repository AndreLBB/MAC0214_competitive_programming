#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int t;
    cin>> t;

    while(t--){
        string a;
        cin >>a;
        int n = a.size();
        string b;
        for (int i = n-1;i>=0;i--){
            if (a[i] == 'p'){
                b.push_back('q');
            }
            else if (a[i]== 'q'){
                b.push_back('p');
            }
            else{
                b.push_back('w');
            }
        }
        cout<<b<<"\n";
    }

}