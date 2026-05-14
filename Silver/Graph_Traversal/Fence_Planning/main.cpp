#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> cows;

class Rectangle{
public:
    int x_min;
    int x_max;
    int y_min;
    int y_max;

    Rectangle(){
        x_min = INT_MAX;
        y_min = INT_MAX;
        x_max = INT_MIN;
        y_max = INT_MIN;
    }

    int perimeter(){
        return 2*(abs(x_max - x_min) + abs(y_max - y_min));
    }
};

void dfs_visit(const vector<vector<int>>& adj, int vertex, vector<bool>& visited, Rectangle& rec){
    visited[vertex] = true;
    rec.x_min = min(rec.x_min, cows[vertex].first);
    rec.x_max = max(rec.x_max, cows[vertex].first);
    rec.y_min = min(rec.y_min, cows[vertex].second);
    rec.y_max = max(rec.y_max, cows[vertex].second);

    for(const auto& neighbor : adj[vertex]){
        if(visited[neighbor]) continue;

        dfs_visit(adj, neighbor, visited, rec);
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        cows.push_back({x, y});

    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    // find the connected components : dfs
    // look at the min and max x and y values to find the area of the fence required for all the connected compoennts
    // find the minimum are a possible

    vector<bool> visited(N, false);
    int min_per = INT_MAX;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;

        Rectangle rec = Rectangle();
        dfs_visit(adj, i, visited, rec);
        min_per = min(min_per, rec.perimeter());
    }

    cout << min_per << "\n";

    
    return 0;
}