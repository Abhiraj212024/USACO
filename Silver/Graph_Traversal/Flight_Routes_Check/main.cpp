#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reverseGraph(const vector<vector<int>>& adjList){
    int n = adjList.size();
    vector<vector<int>> revAdjList(n);

    for(int i = 0; i < n; i++){
        for(const int& v : adjList[i]){
            revAdjList[v].push_back(i);
        }
    }

    return revAdjList;
}

void dfs(const vector<vector<int>>& adjList, vector<int>& state, int u){
    state[u] = 1;

    for(const int& v : adjList[u]){
        if(state[v] == 0){
            dfs(adjList, state, v);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);

    for(int i = 0;i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u-1].push_back(v-1);
    }

    vector<vector<int>> revAdjList = reverseGraph(adjList);

    int u = 0; // vertex 1

    vector<int> state(n, u);

    dfs(adjList, state, 0);

    for(int i = 0; i < n; i++){
        if(state[i] == 0){
            cout << "NO\n" << 1 << " " << i+1 << "\n";
            return 0;
        }
        state[i] = 0;
    }

    dfs(revAdjList, state, u);

    for(int i = 0; i < n; i++){
        if(state[i] == 0){
            cout << "NO\n" << i+1 << " " << 1 << "\n";
            return 0;
        }
        state[i] = 0;
    }

    cout << "YES\n";

    return 0;
}