#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<char>>& maze, vector<vector<bool>>& mask, int x, int y){
    int n = maze.size();
    int m = maze[0].size();

    if(x < 0 || x > n-1 || y < 0 || y > m-1 || mask[x][y] || maze[x][y] == '#') return;

    mask[x][y] = true;

    dfs(maze, mask, x-1, y);
    dfs(maze, mask, x+1, y);
    dfs(maze, mask, x, y-1);
    dfs(maze, mask, x, y+1);
}

bool solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    vector<vector<bool>> mask(n, vector<bool>(m, false));

    dfs(maze, mask, n-1, m-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 'G' && !mask[i][j]){
                return false;
            }

            if(maze[i][j] == 'B'){
                if(i-1 >= 0 && mask[i-1][j] && maze[i-1][j] == 'G') return false;
                if(i+1 < n && mask[i+1][j] && maze[i+1][j] == 'G') return false;
                if(j-1 >= 0 && mask[i][j-1] && maze[i][j-1] == 'G') return false;
                if(j+1 < m && mask[i][j+1] && maze[i][j+1] == 'G') return false;
            }

            if(maze[i][j] == 'B'){
                if(i-1 >= 0 && mask[i-1][j] && maze[i-1][j] == '.') maze[i-1][j] = '#';
                if(i+1 < n && mask[i+1][j] && maze[i+1][j] == '.') maze[i+1][j] = '#';
                if(j-1 >= 0 && mask[i][j-1] && maze[i][j-1] == '.') maze[i][j-1] = '#';
                if(j+1 < m && mask[i][j+1] && maze[i][j+1] == '.') maze[i][j+1] = '#';
            }
        }
    }

    mask = vector<vector<bool>>(n, vector<bool>(m, false));

    dfs(maze, mask, n-1, m-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 'G' && !mask[i][j]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}