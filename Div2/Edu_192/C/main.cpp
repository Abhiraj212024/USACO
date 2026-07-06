#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> freqs;
    int current_freq = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) current_freq++;
        else {
            freqs.push_back(current_freq);
            current_freq = 1;
        }
    }
    freqs.push_back(current_freq);
    sort(freqs.begin(), freqs.end());

    int ways = 0;
    int m = freqs.size();
    int freq_idx = 0;
    int total_deletions = 0;

    while (n > 0 && m > 0) {
        // Find how many deletions we can perform *before* m changes
        // The next element to disappear dictates the limit of this phase
        int max_deletions_in_phase = freqs[freq_idx] - total_deletions;
        
        // We can only count a unique array once per phase of constant m
        bool found_in_phase = false;

        for (int step = 0; step < max_deletions_in_phase; step++) {
            if (n <= 0) break;

            // Check if length k is reachable from this specific state
            if (k >= n && (k - n) % m == 0) {
                found_in_phase = true;
            }

            // Perform the deletion
            n -= m;
            total_deletions++;
        }

        if (found_in_phase) {
            ways++;
        }

        // Clean up elements that have completely vanished
        while (freq_idx < freqs.size() && freqs[freq_idx] <= total_deletions) {
            freq_idx++;
            m--;
        }
    }

    cout << ways << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}