#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& map, int x, int y){
    int n = map.size();
    int m = map[0].size();

    if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '#' || map[x][y] == 'V') return;

    map[x][y] = 'V';

    dfs(map, x-1, y);
    dfs(map, x+1, y);
    dfs(map, x, y-1);
    dfs(map, x, y+1);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == '#' || map[i][j] == 'V') continue;
            count++;
            dfs(map, i, j);
        }
    }


    cout << count << "\n";

    return 0;
}