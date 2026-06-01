#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += static_cast<ll>(a[i]);
        }

        sort(a.begin(), a.end());

        vector<ll> prefix(n, 0);
        vector<ll> suffix(n, 0);
        prefix[0] = a[0];
        suffix[n-1] = a[n-1];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + a[i];
        for(int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] + a[i];

        ll maxSum = LLONG_MIN;

        for(int st_ops = 0; st_ops <= k; st_ops++){
            int end_ops = k-st_ops;

            ll ans = sum;
            ans -= ((st_ops > 0) ? prefix[2*(st_ops) - 1] : 0);
            ans -= ((end_ops > 0) ? suffix[n - end_ops] : 0);

            maxSum = max(maxSum, ans);
        }

        cout << maxSum << "\n";
    }
    return 0;
}