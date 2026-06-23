#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> h(n+1, 0); //price
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<int> s(n+1, 0); // pages
    for(int i = 1; i <= n; i++) cin >> s[i];
    
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j - h[i] < 0) continue;
            dp[i][j] = max(dp[i-1][j], dp[i-1][j - h[i]] + s[i]);
        }
    }

    cout << dp[n][x] << "\n";

    return 0;
}