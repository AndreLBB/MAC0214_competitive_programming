// https://usaco.org/index.php?page=viewproblem2&cpid=1301
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ll N, K;
    cin >> N >> K;

    vector<ll> days(N);

    for (int i = 0; i < N; i++) {
        cin >> days[i];
    }

    ll total = 1 + K;

    for (int i = 1; i < N; i++) {
        ll gap = days[i] - days[i - 1];
        total += min(gap, K + 1);
    }

    cout << total << "\n";
}