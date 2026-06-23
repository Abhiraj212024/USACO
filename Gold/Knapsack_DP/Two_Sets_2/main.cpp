#include <iostream>
#include <vector>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    ll sum = n * (n + 1) / 2;
    if(sum & 1){
        cout << 0 << "\n";
        return 0;
    }
    ll target = sum >> 1;
    vector<vector<int>> dp(n+1, vector<int>(target+1));

    dp[0][0] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            dp[i][j] += dp[i-1][j];

            if(j - i >= 0) dp[i][j] += dp[i-1][j-i];

            dp[i][j] %= MOD;
        }

    }

    cout << dp[n-1][target] << "\n";

    return 0;
}