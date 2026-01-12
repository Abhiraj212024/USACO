#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int s, k, m;
        cin >> s >> k >> m;
        int ans = 0;
        if(m < k){
            ans = max(s-m, 0);
        }else{
            int flips = m/k;
            if(s >= k){
                int amount = (flips % 2) ? k : s;
                ans = max(amount - (m - (flips*k)), 0);
            }else{
                ans = max(s - (m - (flips*k)), 0);
            }
        }
        cout << ans << "\n";

    }
    
    return 0;
}