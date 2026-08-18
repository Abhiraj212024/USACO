#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    // BFS to find depth/distance from root (node 1)
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Queue all initial leaves except target node n
    queue<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (i != n && deg[i] <= 1) {
            leaves.push(i);
        }
    }

    int current_parity = 0; // 0 = even depth, 1 = odd depth
    vector<string> ops;

    while (!leaves.empty()) {
        int leaf = leaves.front();
        leaves.pop();

        int leaf_parity = dist[leaf] % 2;
        if (leaf_parity == current_parity) {
            // Move once so cat's parity flips and differs from leaf_parity
            ops.push_back("1");
            current_parity ^= 1;
        } else {
            // Move twice so cat's parity flips twice and remains different
            ops.push_back("1");
            ops.push_back("1");
        }

        // Destroy leaf safely
        ops.push_back("2 " + to_string(leaf));

        // Update degrees of adjacent nodes
        for (int neighbor : adj[leaf]) {
            deg[neighbor]--;
            if (neighbor != n && deg[neighbor] == 1) {
                leaves.push(neighbor);
            }
        }
    }

    cout << ops.size() << "\n";
    for (const string& op : ops) {
        cout << op << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}