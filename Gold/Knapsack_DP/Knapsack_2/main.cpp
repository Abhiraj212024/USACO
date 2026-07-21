#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main(){
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    ll max_v = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        max_v += a[i].second;
    }

    vector<ll> dp(max_v+1, INT_MAX);
    dp[0] = 0;

    for(const pair<int,int>& p : a){
        int wi = p.first;
        int vi = p.second;
        for(int i = max_v; i >= 1; i--){
            if(i - vi < 0) continue;
            if(dp[i-vi] != INT_MAX){
                dp[i] = min(dp[i], dp[i-vi] + (ll)wi);
            }
        }
    }

    int v_ans = max_v;

    for(int i = max_v; i >= 0; i--){
        if(dp[i] <= (ll)w){
            v_ans = i;
            break;
        }
    }

    cout << v_ans << "\n";

    return 0;
}