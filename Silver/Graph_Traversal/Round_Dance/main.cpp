#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int>>& adjList, vector<int>& state, vector<int>& p, int u){
    state[u] = 1;
    bool hasCycle = false;
    for(const int& v : adjList[u]){
        if(state[v] == 0){
            p[v] = u;
            hasCycle |= (dfs(adjList, state, p, v));
        }else if(state[v] == 1 && v != p[u]){
            hasCycle |= true;
        }
    }

    state[u] = 2;

    return hasCycle;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0;i < n; i++){
            int x;
            cin >> x;
            a[i] = x-1;
        }

        if(n == 2){
            cout << 1 << " " << 1 << "\n";
            continue;
        }

        vector<vector<int>> adjList(n);
        for(int i = 0;i < n; i++){
            adjList[i].push_back(a[i]);
            adjList[a[i]].push_back(i);
        }

        vector<int> state(n, 0);
        vector<int> parents(n, -1);
        int comps = 0;
        int cycle_comps = 0;
        for(int u = 0; u < n; u++){
            if(state[u] > 0) continue;

            comps++;
            if(dfs(adjList, state, parents, u)) cycle_comps++;
        }

        int min_val = 0;
        
        if(cycle_comps == comps){
            min_val = cycle_comps;
        }else{
            min_val = cycle_comps + 1;
        }

        cout << min_val << " " << comps << "\n";

    }
    return 0;
}