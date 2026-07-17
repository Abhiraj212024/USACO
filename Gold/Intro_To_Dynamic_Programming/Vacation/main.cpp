#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    vector<ll> a(n+1, 0);
    vector<ll> b(n+1, 0);
    vector<ll> c(n+1, 0);
    for(int i{1}; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i{1}; i <= n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    return 0;
}