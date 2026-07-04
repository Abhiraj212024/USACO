#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[--u].push_back(--v);
			adj[v].push_back(u);
		}

		// BFS from node 0
		queue<int> q;
		q.push(0);
		vector<int> dist(n, -1);
		dist[0] = 0;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int next : adj[curr]) {
				if (dist[next] == -1) {
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}

		// separates nodes by parity and outputs smaller group
		vector<int> even;
		vector<int> odd;

		for (int i = 0; i < n; i++) {
			(dist[i] % 2 == 0 ? even : odd).push_back(i + 1);
		}
		if (even.size() < odd.size()) {
			cout << even.size() << "\n";
			for (int num : even) { cout << num << " "; }
		} else {
			cout << odd.size() << "\n";
			for (int num : odd) { cout << num << " "; }
		}
		cout << "\n";
	}
}