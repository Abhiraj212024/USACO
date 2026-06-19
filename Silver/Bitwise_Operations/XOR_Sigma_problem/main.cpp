#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;

    for(int k = 0; k < 30; k++){
        int sum = 0;       // tracks total number of 1s in array B
        int n_ones = 0;    // tracks 1s in prefix array C
        int n_zeros = 1;   // tracks 0s in prefix array C (starts at 1 because C[0] = 0)
        
        int current_prefix = 0; 

        for(int i = 0; i < n; i++){
            int b_i = ((a[i] >> k) & 1);
            sum += b_i;

            // Maintain the cumulative prefix XOR on the fly
            current_prefix ^= b_i;

            // Count it towards our prefix distributions
            if(current_prefix == 0){
                n_zeros++;
            } else {
                n_ones++;
            }
        }

        // Use 1LL to prevent integer overflow during the large multiplication
        ll bit_contribution = ((ll)n_ones * n_zeros) - sum;
        ans += bit_contribution * (1LL << k);
    }

    cout << ans << "\n";

    return 0;
}