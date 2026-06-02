#include <iostream>
#include <vector>



using namespace std;

int main(){
    int n;
    cin >> n;
    const long long mod = 7 + 1e9;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                dp[i] = (dp[i]%mod + dp[i-j]%mod)%mod;
            }else{
                break;
            }
        }
    }
    cout << dp[n] % mod << "\n";
    return 0;
}