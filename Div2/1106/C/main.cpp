#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;


void dfs(const vector<vector<int>>& adjList, int u, int p, vector<bool>& visited, vector<int>& depth, vector<int>& dp, vector<ll>& ans){
    visited[u] = true;
    if(p >= 0){
        depth[u] = depth[p] + 1;
    }
    dp[u] = depth[u];
    for(const int& v : adjList[u]){
        if(!visited[v]){
            dfs(adjList, v, u, visited, depth, dp, ans);
        }
    }

    if(adjList[u].size() == 0){
        ans[u] = 1;
        return;
    }
    
    // second largest child depth
    vector<int> temp = {0};
    ll sum = 0;
    for(const int& v : adjList[u]){
        dp[u] = max(dp[u], dp[v]);
        int L_t0 = dp[v] - depth[u];
        temp.push_back(L_t0);
        sum += ans[v];
    }

    sort(temp.begin(), temp.end());
    int m2 = temp[temp.size()-2];

    ans[u] = 1LL + m2 + sum;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adjList(n);
        for(int i = 2; i <= n; i++){
            int p;
            cin >> p;
            adjList[p-1].push_back(i-1);
        }

        vector<int> depth(n, 0);
        vector<int> dp(n, 0);
        vector<bool> visited(n, false);
        vector<ll> ans(n, 0);

        dfs(adjList, 0, -1, visited, depth, dp, ans);

        cout << ans[0] << "\n";
    }
    return 0;
}