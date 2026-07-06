#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> h(n);
        ll minIdx = 0;
        for(int i = 0;i < n; i++){
            cin >> h[i];
            if(h[i] < h[minIdx]){
                minIdx = i;
            }
        }

        vector<ll> h_new(n);
        vector<int> orig_to_shifted(n);
        for(int i = 0;i < n; i++){
            int shift_idx = (i + n - 1 - minIdx) % n;
            h_new[shift_idx] = h[i];
            orig_to_shifted[i] = shift_idx;
        }

        vector<ll> R(n, 0);
        vector<ll> L(n, 0);
        vector<int> st;

        for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && h_new[st.back()] >= h_new[i]) {
                st.pop_back();
            }
            if (st.empty()) {
                // No smaller element to the right, it goes up to the global min at the boundary
                R[i] = h_new[i] * (n - 1 - i);
            } else {
                int nxt = st.back();
                R[i] = h_new[i] * (nxt - i) + R[nxt];
            }
            st.push_back(i);
        }

        st.clear();

        // 2. Compute Left DP (L) using a monotonic stack
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && h_new[st.back()] >= h_new[i]) {
                st.pop_back();
            }
            if (st.empty()) {
                // No smaller element to the left, bounded by the beginning of our unrolled array
                L[i] = h_new[i] * i;
            } else {
                int prev = st.back();
                L[i] = h_new[i] * (i - prev) + L[prev];
            }
            st.push_back(i);
        }

        // 3. Reconstruct answers for each original vessel position
        for (int i = 0; i < n; ++i) {
            int idx = orig_to_shifted[i];
            
            long long ans = 0;
            
            // Water flowing clockwise (Right side of the boundary)
            if (idx < n - 1) {
                ans += R[idx];
            }
            // Water flowing counter-clockwise (Left side of the boundary)
            if (idx > 0) {
                ans += L[idx - 1];
            }

            cout << ans << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}