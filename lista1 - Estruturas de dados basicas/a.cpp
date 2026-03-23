#include <bits/stdc++.h> 
#include <deque>
#include <iostream>
using namespace std; 
#define ll long long


int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
cout.tie(NULL);

    ll k;
    cin >> k;
    for (ll w = 0;w<k;w++){

        ll n_op, op, valor,r = 0;
        cin >> n_op;
        ll somatorio_simples = 0;
        ll size = 0;
        deque<ll> v;
        int invertido = 0;
        for (int i = 0; i< n_op;i++){
            cin >> op;
            if (op == 3){
                cin >> valor;
                somatorio_simples += valor;
                size++;
                if (invertido == 0){
                    v.push_back(valor);
                }
                else{
                    v.push_front(valor);
                }
                r += valor * size;
                cout << r << "\n";
            }
            else{
                if (op == 2){
                    r = (size +1) * somatorio_simples - r;
                    if (invertido == 0) {
                        invertido = 1;
                    }
                    else{
                        invertido = 0;
                    }

                    cout << r << "\n";
                }
                else{
                    if (op == 1){
                    ll ultimo;

                    if (invertido == 0){
                        ultimo = v.back();
                        v.pop_back();
                        v.push_front(ultimo);
                    }
                    else{
                        ultimo = v.front();
                        v.pop_front();
                        v.push_back(ultimo);
                    }
                    r = r + somatorio_simples - ultimo * size;
                    
                    cout << r << "\n";
                    }
                }
            }
            
        }

    }

    




    return 0;
}