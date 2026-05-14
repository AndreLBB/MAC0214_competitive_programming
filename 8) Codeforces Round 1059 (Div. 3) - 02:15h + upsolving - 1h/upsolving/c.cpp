#include <bits/stdc++.h> 
using namespace std; 
#define ll long long



// a^c = b
// a^a^c = a^b
// 0 ^c = a^b
// c = a^b
int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

int t; cin >> t;
while(t--){
    int a,b;
    cin>>a>>b;
    if (__builtin_clz(a) > __builtin_clz(b)) cout << "-1"<<"\n"; // aqui msb(a)<msb(b)
    else if (__builtin_clz(a) == __builtin_clz(b)){

        // nesse caso o msb(a) == msb(b)
        // a^b vai ter msb() menor que a, logo segue a restrição
        int c = a^b;
        if (c == 0) cout<<"0\n";
        else{
        cout<<"1"<<"\n"<<c<<"\n";
        }
    }
    else{

        // nesse caso msb(a) > msb(b)
        // agora a^b pode ter msb() = msb(a) e aí pode dar ruim na restrição
        // entao fazemos a ser o maior possivel com o primeiro xor,
        // construindo um x tal que a xor x dê 111111111111111...
        // esse x seria 111111.... xor a pq aí a xor x = a xor a xor 111111.....

        // agr que a é gigante 11111111.., não tem risco que a^b seja maior que a
        // entao podemos fazeer a^b, assim temos dois x's
        cout<<"2"<<"\n";


        // isso aqui (1LL << (32 - __builtin_clz(a))) é tipo 100000 com um 
        // 1 mais a direita que o msb(a) e ao fazer -1 vira 011111111 com 
        // 1 exatamente na pos do masb(a)
        // long long pq o cara poderia usar o maior int possivel e aí nessa
        // de ter 1 a mais direita que o msb(a) dar overflow
        long long temp = (1LL << (32 - __builtin_clz(a))) - 1;  
        long long x = a ^ temp;
        cout<<x<<" ";

        a = a^x;
        x = a^b;
        cout<<x<<"\n";


    }
 

}
return 0;
}