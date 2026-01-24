#include <iostream>
#include <vector>
using namespace std;

int main(){

    // precompute

    vector<vector<int>> nCr(31, vector<int>(31, 0));

    // n C 0 = 1

    for(int i = 0; i < 31; ++i){
        for(int j = 0; j < 31; ++j){
            if (i < j) nCr[i][j] = 0;
            else if (j == 0) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int d = 0;
        while ((n & 1) == 0){
            n>>=1;
            d++;
        }

        int ans = 0;
        for(int max_bit = 0; max_bit < d; max_bit++){
            for(int cnt_bit = 1; cnt_bit <= d+1; cnt_bit++){
                if(max_bit + cnt_bit <= k) continue;
                ans += nCr[max_bit][cnt_bit-1];
            }
        }

        if(d+1 > k){
            ans++;
        }

        cout << ans << "\n";

    }
    return 0;
}