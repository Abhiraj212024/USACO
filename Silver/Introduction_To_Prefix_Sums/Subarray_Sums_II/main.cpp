#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Speed up I/O
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<long long, int> freq;
    freq[0] = 1; // Base case: an empty prefix sum is 0
    
    long long current_prefix_sum = 0;
    long long total = 0;

    for(int i = 0; i < n; i++) {
        current_prefix_sum += arr[i];
        
        // Check if (current_prefix_sum - x) exists in the map
        if(freq.count(current_prefix_sum - x)) {
            total += freq[current_prefix_sum - x];
        }
        
        // Add current prefix sum to the map for future indices
        freq[current_prefix_sum]++;
    }

    cout << total << "\n";

    return 0;
}