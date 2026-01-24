#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        if(n == k){
            cout << 0 << "\n";
            continue;
        }

        int l = n;
        int r = n;
        int iteration = 0;
        int ans = -1;
        while(r != 1){
            if(l <= k && k <= r){
                ans = iteration;
                break;
            }

            l = l/2;
            r = r - (r/2);

            iteration++;
        }

        if(l <= k && k <= r){
            ans = iteration;
        }

        cout << ans << "\n";
    }
    return 0;
}
