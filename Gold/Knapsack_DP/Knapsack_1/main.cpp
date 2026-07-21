#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

int main(){
    int n, w;
    cin >> n >> w;

    vector<ll> dp(w+1, INT_MIN);
    dp[0] = 0;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    for(const pair<int, int>& p : a){
        int wi = p.first;
        int vi = p.second;

        for(int i = w; i >= 1; i--){
            if(i - wi < 0) continue;
            if(dp[i-wi] != INT_MIN){
                dp[i] = max(dp[i], dp[i-wi] + (ll)vi);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}