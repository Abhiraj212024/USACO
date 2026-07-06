#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pref1(n + 1, 0), pref2(n + 1, 0), pref3(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref1[i + 1] = pref1[i] + (a[i] == 1);
        pref2[i + 1] = pref2[i] + (a[i] == 2);
        pref3[i + 1] = pref3[i] + (a[i] == 3);
    }

    // F[i] represents the balance at the end of a prefix of length i
    vector<int> F(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        F[i] = pref1[i] + pref2[i] - pref3[i];
    }

    // Build suffix maximum array for F from index 2 to n-1 (corresponds to valid m values)
    vector<int> suff_max(n + 1, -1e9);
    suff_max[n - 1] = F[n - 1];
    for (int i = n - 2; i >= 1; i--) {
        suff_max[i] = max(F[i], suff_max[i + 1]);
    }

    // j is the length of Part 1 (must leave at least 2 elements for Part 2 and Part 3)
    for (int j = 1; j <= n - 2; j++) {
        int c1 = pref1[j];
        int c2 = pref2[j];
        int c3 = pref3[j];

        // Check if Part 1 condition holds
        if (c1 >= c2 + c3) {
            // Check if there is any valid m such that F[m] >= F[j]
            if (suff_max[j + 1] >= F[j]) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}