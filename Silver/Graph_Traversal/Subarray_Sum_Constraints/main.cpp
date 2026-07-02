#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<ll> pref(n + 1, LLONG_MIN);
    // Build an undirected graph where each edge stores the neighbor and the weight
    // weight is such that pref[neighbor] = pref[curr] + weight
    vector<vector<pair<int, ll>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        ll a, b, s;
        cin >> a >> b >> s;
        int u = a - 1;
        int v = b;
        // P[v] - P[u] = s  =>  P[v] = P[u] + s
        adj[u].push_back({v, s});
        // P[u] = P[v] - s
        adj[v].push_back({u, -s});
    }

    // Traverse all components
    for(int i = 0; i <= n; i++){
        if(pref[i] == LLONG_MIN){
            pref[i] = 0; // Start component with an arbitrary anchor value
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(auto &[nxt, diff] : adj[curr]){
                    if(pref[nxt] == LLONG_MIN){
                        pref[nxt] = pref[curr] + diff;
                        q.push(nxt);
                    } else if(pref[nxt] != pref[curr] + diff){
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
    }

    // Reconstruct original x array
    vector<ll> x(n);
    for(int i = 1; i <= n; i++){
        x[i-1] = pref[i] - pref[i-1];
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++){
        cout << x[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}