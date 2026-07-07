#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    
    long long total_popcount = 0;
    long long current_bit_val = 1; // Represents 2^0, 2^1, 2^2, etc.
    
    while (n > 0 && current_bit_val <= n) {
        // You can take at most k bits for the current power of 2
        long long take = min(k, n / current_bit_val);
        
        total_popcount += take;
        n -= take * current_bit_val;
        
        // Move to the next bit power (next column)
        current_bit_val *= 2;
    }
    
    cout << total_popcount << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}