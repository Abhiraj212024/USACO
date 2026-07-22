#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reconstructPath(const vector<vector<int>>& dp, const string& s){
    int n = dp.size() - 1;
    int m = dp[0].size() - 1;
    int i = n;
    int j = m;
    string ans;
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]){
            i--;
        }else if(dp[i][j] == dp[i][j-1]){
            j--;
        }else{
            ans += s[i-1];
            i--;
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << reconstructPath(dp, s) << "\n";
    return 0;
}