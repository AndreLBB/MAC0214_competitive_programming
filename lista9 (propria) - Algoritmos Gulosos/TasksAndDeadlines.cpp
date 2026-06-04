// https://cses.fi/problemset/task/1630
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll n;
    cin>>n;
    vector<pair<ll,ll>> tasks(n);
    for (int i = 0;i<n;i++){
        cin>>tasks[i].first>>tasks[i].second; 
        // (duracao, deadline)
    }
    sort(tasks.begin(), tasks.end());
    ll time = 0;
    ll total =0;
    for (auto task: tasks){
        ll reward = task.second - (time + task.first);
        total +=reward;
        time += task.first;
    }
    cout<< total<<"\n";

}