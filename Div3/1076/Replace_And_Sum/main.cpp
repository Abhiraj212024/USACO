#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<int> max_vec(n, 0);
        int max_val = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            max_val = max(max(a[i], b[i]), max_val);
            max_vec[i] = max_val;
        }

        vector<int> p(n+1, 0);
        for(int i = 1; i <= n; i++){
            p[i] = p[i-1] + max_vec[i-1];
        }

        while(q--){
            int l, r;
            cin >> l >> r;

            int sum = p[r] - p[l-1];

            cout << sum << " ";
        }

        cout << "\n";

    }
    return 0;
}