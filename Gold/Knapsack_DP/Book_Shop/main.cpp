#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> h(n+1, 0); //price
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<int> s(n+1, 0); // pages
    for(int i = 1; i <= n; i++) cin >> s[i];
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; i++){
        v.push_back({h[i], s[i]});
    }
    sort(v.begin(), v.end());
    vector<int> dp(x+1, INT_MIN); // dp[i] -> maximum number of pages for price i
    dp[0] = 0;
    for(const pair<int, int>& p : v){
        int price = p.first;
        int pages = p.second;

        for(int j = x; j >= 1; j--){
            if(j - price < 0) continue;
            if(dp[j-price] != INT_MIN){
                dp[j] = max(dp[j], dp[j-price] + pages);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}