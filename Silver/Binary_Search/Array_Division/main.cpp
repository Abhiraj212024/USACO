#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;

#define LL long long

LL first_true(LL lo, LL hi, const vector<LL>& a, LL k, function<bool(vector<LL>, LL, LL)> f){
    hi++;
    while(lo < hi){
        LL mid = lo + (hi - lo) / 2;

        if(f(a, k, mid)){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }

    return lo;
}

bool comp(const vector<LL>& a, LL k, LL m){
    LL n_subarr = 0;
    long sum = 0;

    for(LL i = 0; i < a.size(); i++){
        if(sum + a[i] <= m){
            sum += a[i];
        }else{
            n_subarr++;
            sum = a[i];
        }
    }

    n_subarr++;

    return (n_subarr <= k);
}

int main(){
    int n,k;
    cin >> n >> k;

    vector<LL> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    LL l = *max_element(a.begin(), a.end());
    LL r = accumulate(a.begin(), a.end(), 0LL);

    cout << first_true(l, r, a, k, comp) << "\n";

    return 0;
}