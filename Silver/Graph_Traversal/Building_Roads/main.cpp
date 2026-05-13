#include <iostream>
#include <vector>

using namespace std;

void dfs_visit(const vector<vector<int>>& adj, int vertex, vector<bool>& visited){
    visited[vertex] = true;
    for(const auto& neighbor : adj[vertex]){
        if(visited[neighbor]) continue;
        dfs_visit(adj, neighbor, visited);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){

        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    // let c -> number of connected componenets in the graph (find using dfs), then add c-1 roads
    vector<bool> visited(n, 0);
    int c = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;

        c++;
        ans.push_back(i);
        dfs_visit(adj, i, visited);
    }

    cout << c-1 << "\n";
    for(int i = 0; i < c-1; i++){
        cout << ans[i]+1 << " " << ans[i+1]+1 << "\n";
    }

    return 0;
}
