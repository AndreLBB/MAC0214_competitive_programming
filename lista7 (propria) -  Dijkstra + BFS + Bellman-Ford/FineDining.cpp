// https://usaco.org/index.php?page=viewproblem2&cpid=861
#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);


    int V, E, K;
    if (!(cin >> V >> E >> K)) return 0;

    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> feno(V, 0);
    for (int i = 0; i < K; i++) {
        int u, y;
        cin >> u >> y;
        feno[u - 1] = max(feno[u - 1], y);
    }

    vector<vector<int>> dist_a_u(V, vector<int>(2, INT_MAX));
    int celeiro = V - 1;
    dist_a_u[celeiro][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {celeiro, 0}});

    if (feno[celeiro] > 0) {
        dist_a_u[celeiro][1] = -feno[celeiro];
        pq.push({dist_a_u[celeiro][1], {celeiro, 1}});
    }

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second.first;
        int estado = pq.top().second.second;
        pq.pop();

        if (d > dist_a_u[v][estado]) continue;

        for (auto [k, w] : adj[v]) {
            if (dist_a_u[v][estado] == INT_MAX) continue;

            if (dist_a_u[k][estado] > dist_a_u[v][estado] + w) {
                dist_a_u[k][estado] = dist_a_u[v][estado] + w;
                pq.push({dist_a_u[k][estado], {k, estado}});
            }

            if (estado == 0 && feno[k] > 0) {
                if (dist_a_u[k][1] > dist_a_u[v][0] + w - feno[k]) {
                    dist_a_u[k][1] = dist_a_u[v][0] + w - feno[k];
                    pq.push({dist_a_u[k][1], {k, 1}});
                }
            }
        }
    }

    for (int i = 0; i < V - 1; i++) {
        if (dist_a_u[i][1] <= dist_a_u[i][0]) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}