#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);

        for(int i = 0;i < n; i++) cin >> a[i];
        for(int i = 0;i < n; i++) cin >> b[i];
        for(int i = 0;i < n; i++) cin >> c[i];

        vector<long long> dp(8, LLONG_MIN);
        dp[0] = 0; // no way to reach 0 state initially

        for(int i = 0; i < n; ++i){
            vector<long long> next_dp = dp;

            for(int mask = 0; mask < 8; ++mask){
                if(dp[mask] == LLONG_MIN) continue;

                if((mask & 1) == 0){
                    next_dp[mask | 1] = max(next_dp[mask | 1], dp[mask] + a[i]);
                }

                if((mask & 2) == 0){
                    next_dp[mask | 2] = max(next_dp[mask | 2], dp[mask] + b[i]);
                }

                if((mask & 4) == 0){
                    next_dp[mask | 4] = max(next_dp[mask | 4], dp[mask] + c[i]);
                }
            }

            dp = next_dp;
        }

        cout << dp[7] << "\n";
    }
}