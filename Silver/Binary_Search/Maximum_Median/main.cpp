#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int last_true(int lo, int hi, function<bool(int)> f){
    // if none in range satisfy, return lo -1
    lo--;
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2; // +1 to round up
        if(f(mid)){
            // search right
            lo = mid;
        }else{
            // search left
            hi = mid-1;
        }
    }

    return lo;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i{}; i < n; i++) cin >> a[i];

    if(n == 1){
        cout << a[0] + k << "\n";
        return 0;
    }

    sort(a.begin(), a.end());

    // n is odd
    int ans = last_true(1, 2e9, [&](int x){
        // return true if median can be raised to x
        long long ops_needed = 0;
        for(int i = (n - 1) / 2; i < n; i++){
            ops_needed += max(0, x - a[i]);
        }

        return ops_needed <= k;
    });

    cout << ans << "\n";

    return 0;
}