#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        vector<ll> a(n, 0);
        for(int i = 0;i < n; i++) cin >> a[i];
        vector<ll> k(q, 0);
        for(int i = 0; i < q; i++) cin >> k[i];

        vector<ll> h(n, 0);
        vector<ll> max_a(n, 0);
        h[0] = a[0];
        max_a[0] = a[0];
        for(int i = 1;i < n; i++){
            h[i] = h[i-1] + a[i];
            max_a[i] = max(max_a[i-1], a[i]);
        }

        for(int i = 0;i < q; i++){
            int idx = upper_bound(max_a.begin(), max_a.end(), k[i]) - max_a.begin();
            
            // can go only uptil idx - 1
            if(idx == 0){
                cout << 0 << " ";
            }else{
                cout << h[idx-1] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}