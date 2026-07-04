#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


void dfs(const vector<vector<int>>& adj, int u, vector<int>& state, vector<int>& top_sort){
    state[u] = 1;

    for(const int& v : adj[u]){
        if(state[v] == 0){
            dfs(adj, u, state, top_sort);
        }
    }

    state[u] = 2;
    top_sort.push_back(u);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
 
    for(int i = 0; i < n-1; i++){
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i+1);
    }

    vector<int> top_sort;
    vector<int> state(n, 0);
    for(int u = 0; u < n; u++){
        if(state[u] > 0) continue;

        dfs(adj, u, state, top_sort);
    }

    vector<ll> sub(n, 0LL);

    for(int i = top_sort.size() - 1; i >= 0; i--){
        int v = top_sort[i];
        for(const int& u : adj[v]){
            sub[v] += 1 + sub[u];
        }
    }

    for(const ll& num : sub){
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}