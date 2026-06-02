#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> bfs_trav(n);
    vector<int> dfs_trav(n);
    for(int i = 0;i < n; i++) cin >> bfs_trav[i];
    for(int i = 0;i < n; i++) cin >> dfs_trav[i];

    if(bfs_trav[1] != dfs_trav[1]){
        cout << -1 << "\n";
        return 0;
    }

    vector<vector<int>> edges;
    set<vector<int>> s;

    for(int i = 1;i < n; i++){
        edges.push_back({bfs_trav[0], bfs_trav[i]});
        s.insert({bfs_trav[0], bfs_trav[i]});
    }

    for(int i = 0; i < n-1; i++){
        if(s.find({dfs_trav[i], dfs_trav[i+1]}) != s.end()) continue;
        if(dfs_trav[i] < dfs_trav[i+1]){
            edges.push_back({dfs_trav[i], dfs_trav[i+1]});
            s.insert({dfs_trav[i], dfs_trav[i+1]});
        }else{
            edges.push_back({dfs_trav[i+1], dfs_trav[i]});
            s.insert({dfs_trav[i+1], dfs_trav[i]});
        }
    }
    
    for(const vector<int>& edge : edges){
        cout << edge[0] << " " << edge[1] << "\n";
    }
    
    return 0;
}