#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define SQUARE(x) ((x) * (x))

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> cows;

    vector<int> P;

    for(int i = 0;i < N; i++){
        int x, y, p;
        cin >> x >> y >> p;
        cows.push_back({x, y});
        P.push_back(p*p);
    }

    vector<vector<int>> D(N, vector<int>(N, 0));

    // precompute square distance from u to v based on range of u
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            D[i][j] = SQUARE((cows[i].first - cows[j].first)) + SQUARE((cows[i].second - cows[i].second));
        }
    }

    // find the largest connected component, do bfs with all elements reachable from the vertex v
    queue<int> Q;
    vector<bool> visited(N, false);
    
    int max_count = INT_MIN; 

    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        int count = 0;
        Q.push(i);
        visited[i] = true;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            count++;

            for(int v = 0; v < N; v++){
                if(D[u][v] > P[u]) continue; // not reachable
                if(visited[v]) continue;

                visited[v] = true;
                Q.push(v);

            }
        }

        max_count = max(max_count, count);

    }

    cout << max_count << "\n";

    return 0;
}