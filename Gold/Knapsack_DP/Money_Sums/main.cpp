#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    int maxVal = accumulate(x.begin(), x.end(), 0);
    vector<bool> dp(maxVal+1, false);
    dp[0] = true;

    for(const int& num : x){
        for(int i = maxVal; i >= 1; i--){
            if(i-num < 0) break;
            dp[i] = dp[i] || dp[i-num];
        }
    }
    int total = accumulate(dp.begin(), dp.end(), 0) - 1; // dp[0]
    cout << total << "\n";
    for(int i = 1; i <= maxVal; i++){
        if(dp[i]){
            cout << i << " ";
        }
    }
    cout << "\n";

    return 0;
}