#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        vector<int> sorted_a(a.begin() + 1, a.end());
        sort(sorted_a.begin(), sorted_a.end());

        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + sorted_a[i];
        }

        int ans = n+1;
        // how many can you beat
        for(int k = 0; k <= n; k++){
            if(prefix[k] > m) break;

            ans = min(ans, n - k + 1);
    
            // case 2: if we can also beat opponent k+1, our place improves to n - k.
			if (k + 1 > n) continue;
			int cost_with;

			if (k == 0) {
				cost_with = a[k + 1];
			} else {
				// cheapest k-1 after removing opponent k+1, plus a[k+1]
				int excl;
				if (a[k + 1] <= sorted_a[k - 1]) {
					excl = prefix[k] - a[k + 1];
				} else {
					excl = prefix[k - 1];
				}

				cost_with = excl + a[k + 1];
			}

			if (cost_with <= m) { ans = min(ans, n - k); }
            
        }

        cout << ans << "\n";
    }
    return 0;
}