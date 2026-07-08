#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int weight; // 0 for same identity (Type 2), 1 for different identity (Type 1)
};

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<Edge>> adj(N + 1);
    for (int k = 0; k < Q; ++k) {
        int type, i, j;
        cin >> type >> i >> j;
        int weight = (type == 1) ? 1 : 0;
        adj[i].push_back({j, weight});
        adj[j].push_back({i, weight}); // Treat as undirected
    }

    vector<int> color(N + 1, -1); // -1: unvisited, 0: Group A, 1: Group B
    int total_parasites = 0;

    for (int i = 1; i <= N; ++i) {
        if (color[i] != -1) continue; // Already processed

        // Start BFS for a new connected component
        queue<int> q;
        q.push(i);
        color[i] = 0;

        int count0 = 0, count1 = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (color[u] == 0) count0++;
            else count1++;

            for (auto& edge : adj[u]) {
                int v = edge.to;
                int w = edge.weight;

                int expected_color = (w == 1) ? (1 - color[u]) : color[u];

                if (color[v] == -1) {
                    color[v] = expected_color;
                    q.push(v);
                } else if (color[v] != expected_color) {
                    // Contradiction found
                    cout << -1 << "\n";
                    return;
                }
            }
        }

        // For this independent component, pick the assignment that gives more parasites
        total_parasites += max(count0, count1);
    }

    cout << total_parasites << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}