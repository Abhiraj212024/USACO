#include <iostream>
#include <vector>
#include <climits>
#include <cmath> // For abs

#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> h(n+1, 0);
    for(int i{1}; i <= n; i++) cin >> h[i];
    
    // Use a large value like 1e18 for long long DP to avoid overflow issues
    vector<ll> dp(n+1, 1e18); 
    dp[1] = 0; // Base case: starting at stone 1 costs 0

    for(int i{2}; i <= n; i++){
        // j can only go up to i-1 so that we don't land on index 0
        for(int j{1}; j <= min(k, i-1); j++){
            dp[i] = min(dp[i-j] + abs(h[i] - h[i-j]), dp[i]);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}