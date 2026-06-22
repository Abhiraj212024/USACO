#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<ll>> count(10, vector<ll>(n+1, 0));
    for(int i = 1;i <= n; i++){
        int d = s[i-1] - '0';
        count[d][i]++;
    }
    for(int d = 0; d < 10; d++){
        for(int i = 1; i <= n; i++){
            count[d][i] += count[d][i-1];
        }
    }

    vector<ll> bitmask(n+1, 0);
    for(int i = 1; i <= n; i++){
        for(int d = 0; d < 10; d++){
            bitmask[i] |= ((count[d][i] & 1LL) << d); // 1 for odd, 0 for even
        }
    }

    // find number of integers with same value in bitmask, add nC2 for each value
    unordered_map<ll, ll> m;
    for(int i = 0; i <= n; i++){
        m[bitmask[i]]++;
    }

    ll ans = 0;
    for(const auto& [key, freq] : m){
        ans += (freq * (freq-1))/2;
    }

    cout << ans << "\n";


    return 0;
}