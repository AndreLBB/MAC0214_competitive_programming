#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

// 00000000111111

// como nao sei codar bem o negocio de ser palindromo
// estou levando tempo

// entao x ou p podem ser string vazia
// da pra fazer em O(n^4)

// 010
// {}
// 0
// 01
// 00
//1

// 001
// {}
// 0
// 01
// 00
// 1
// 001


// 11010011
// 

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

int t; cin >> t;
while(t--){
    int n; cin >> n;
    vector<char> s(n);
    vector<int> indices;
    for (int i=0;i<n;i++){
        cin>> s[i];
        if (s[i]=='0'){
            indices.push_back(i);
        }
    }
    cout<< indices.size()<<"\n";
    for(int a : indices){
        cout<< a+1<<" ";
    }
    cout<< "\n";

    
}
return 0;
}