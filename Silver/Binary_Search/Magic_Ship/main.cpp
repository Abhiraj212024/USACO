#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

bool isPossible(const pair<int, int>& start, const pair<int, int>& end, long long d, const vector<vector<int>>& DIRECTIONS){
    
    long long n = DIRECTIONS[0].size();
    long long wind_up = (d / n) * DIRECTIONS[0][n-1] + ((d%n > 0) ? DIRECTIONS[0][(d%n - 1)] : 0);
    long long wind_down = (d / n) * DIRECTIONS[1][n-1] + ((d%n > 0) ? DIRECTIONS[1][(d%n - 1)] : 0);
    long long wind_left = (d / n) * DIRECTIONS[2][n-1] + ((d%n > 0) ? DIRECTIONS[2][(d%n - 1)] : 0);
    long long wind_right = (d / n) * DIRECTIONS[3][n-1] + ((d%n > 0) ? DIRECTIONS[3][(d%n - 1)] : 0);

    long long wind_y = wind_up - wind_down;
    long long wind_x = wind_right - wind_left;

    long long req_y = abs(end.second - start.second - wind_y);
    long long req_x = abs(end.first - start.first - wind_x);

    return (req_x + req_y <= d);
    
}

int main(){

    pair<int, int> start;
    pair<int, int> end;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;

    int n;
    cin >> n;
    string s{};
    cin >> s;

    // prefix sums of directions uptil day d

    vector<vector<int>> DIRECTIONS(4, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        char dir = s[i];
        if(dir == 'U'){
            DIRECTIONS[0][i] = 1;
        }else if(dir == 'D'){
            DIRECTIONS[1][i] = 1;
        }else if(dir == 'L'){
            DIRECTIONS[2][i] = 1;
        }else if(dir == 'R'){
            DIRECTIONS[3][i] = 1;
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 1; j < n; j++){
            DIRECTIONS[i][j] += DIRECTIONS[i][j-1];
        }
    }

    long long lo = 0;
    long long hi = 1e15;

    long long valid = -1;
    while(lo <= hi){
        long long mid = lo + (hi-lo)/2;

        if(isPossible(start, end, mid, DIRECTIONS)){
            // try searching for lower val
            valid = mid;
            hi = mid-1;
        }else{
            // go right;
            lo = mid+1;
        }
    }

    cout << valid << "\n";

    return 0;
}