#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> adjList(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<int> color(n, 0);
    queue<int> q;

    int u = 0;
    visited[u] = true;
    color[u] = 1;
    q.push(u);

    long long n_ones = 1;
    long long n_twos = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(const int& w : adjList[v]){
            if(!visited[w]){
                q.push(w);
                visited[w] = true;
                if(color[v] == 1){
                    color[w] = 2;
                    n_twos++;
                }
                else{
                    color[w] = 1;
                    n_ones++;
                }
            }
        }
    }

    // you can form an edge every vertex colored differently
    cout << (n_ones * n_twos) - (long long)(n - 1) << "\n";

    return 0;
}