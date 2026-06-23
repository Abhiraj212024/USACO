#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

const ll MOD = 998244353;

int main(){
    int q, k;
    cin >> q >> k;
    vector<ll> dp(k+1, 0);
    dp[0] = 1;
    while(q--){
        char op;
        int x;
        cin >> op >> x;
        if(op == '+'){
            for(int i = k; i >= x; i--){
                dp[i] = (dp[i] % MOD + dp[i-x] % MOD) % MOD;
            }
        }else{
            for(int i = x; i <= k; i++){
                dp[i] = (dp[i] % MOD - dp[i-x] % MOD) % MOD;
            }
        }

        cout << dp[k] << "\n";
    }
    return 0;
}