#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Use long long for the sum and count to prevent overflow
    long long prefix_sum = 0;
    long long count = 0;
    
    // Frequency map for remainders
    unordered_map<int, long long> freq;
    freq[0] = 1; // Base case: remainder 0 has appeared once (empty prefix)

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        prefix_sum += val;

        // Normalize remainder to be in range [0, n-1]
        int rem = ((prefix_sum % n) + n) % n;

        // Add the number of times we've seen this remainder before
        count += freq[rem];

        // Increment the frequency for future encounters
        freq[rem]++;
    }

    cout << count << "\n";
    return 0;
}