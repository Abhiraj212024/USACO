#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<ll> pref_sum(n+1, 0);
        vector<ll> pref_xor(n+1, 0);
        for(int i = 1; i <= n; i++){
            pref_sum[i] = pref_sum[i-1] + a[i-1];
            pref_xor[i] = pref_xor[i-1] ^ a[i-1];
        }

        auto cost = [&](int l, int r){
            return (pref_sum[r] - pref_sum[l-1]) - (pref_xor[r] ^ pref_xor[l-1]);
        };

        int L, R;
        cin >> L >> R;

        ll best_cost = cost(L, R);

        int lo = L;
        int hi = R;

        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            bool possible = false;

            for(int i = L; i + mid - 1 <= R; i++){
                if(cost(i, i + mid - 1) == best_cost){
                    possible = true;
                    break;
                }
            }

            if(possible){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }

        for(int i = L; i + lo - 1 <= R; i++){
            if(cost(i, i + lo -1) == best_cost){
                cout << i << " " << i + lo - 1 << "\n";
                break;
            }
        }
    }
    return 0;
}