#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool check(const vector<ll>& a, ll h, ll w){
    ll count = 0;
    for(const ll& num : a){
        count += (max(h - num, 0LL));
    }
    return (count <= w);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        ll lo = 1;
        ll hi = INT_MAX;
        lo--;
        while(lo < hi){
            ll mid = lo + (hi-lo+1)/2;

            if(check(a, mid, x)){
                // go right
                lo = mid;
            }else{
                hi = mid-1;
            }
        }

        cout << lo << "\n";
    }
    return 0;
}