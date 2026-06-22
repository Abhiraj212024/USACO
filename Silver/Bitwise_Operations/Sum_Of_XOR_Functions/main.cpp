#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define ll long long

using namespace std;

const ll MOD = 998244353;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> px(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        px[i+1] = px[i] ^ a[i];
    }
    ll ans = 0;
    for(int k = 0; k <= 30; k++){
        ll zero_idx_sum = 0;
        ll one_idx_sum = 0;
        ll n_zero = 0;
        ll n_one = 0;
        ll sum = 0;
        for(int i = 0; i <= n; i++){
            if((px[i] >> k) & 1){
                n_one++;
                one_idx_sum += i;
                sum = sum % MOD + ((i)*n_zero - zero_idx_sum) % MOD;
            }else{
                n_zero++;
                zero_idx_sum += i;
                sum = sum % MOD + ((i) * n_one - one_idx_sum) % MOD;
            }
        }

        ans = ((ans % MOD) + (sum << k) % MOD) % MOD;
    }

    cout << ans << "\n";

    return 0;
}