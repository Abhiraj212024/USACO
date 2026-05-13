#include <iostream>
#include <vector>

using namespace std;

int dfs_visit(const vector<vector<int>>& adj, int vertex, vector<int>& color, vector<bool>& visited){

    visited[vertex] = true;

    int c = color[vertex];
    for(const auto& neighbor : adj[vertex]){
        if(color[neighbor] == c){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if(visited[neighbor]) continue;
        color[neighbor] = (c == 1) ? 2 : 1;
        if(!dfs_visit(adj, neighbor, color, visited)) return 0;
    }

    return 1;
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

    // bipartite check, start dfs and color alternatively in one shot, if ever find a neighbor with same color, return IMPOSSIBLE


    vector<int> color(n, 0);
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        if(visited[i]) continue;

        color[i] = 1;
        if(!dfs_visit(adj, i, color, visited)) return 0;
    }

    for(int i = 0; i < n; i++){
        cout << color[i] << " ";
    }
    cout << "\n";
    return 0;
}
