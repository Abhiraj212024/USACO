#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    Checks whether s[i..i+2] forms a moo.
    If yes, stores the pattern (x, y) where xyy.
*/
bool isMoo(const string& s, int i, int& x, int& y) {
    if (s[i] != s[i + 1] && s[i + 1] == s[i + 2]) {
        x = s[i] - 'a';
        y = s[i + 1] - 'a';
        return true;
    }
    return false;
}

int main() {
    int N, F;
    cin >> N >> F;

    string s;
    cin >> s;

    // count[x][y] = number of occurrences of moo "xyy"
    vector<vector<int>> count(26, vector<int>(26, 0));

    // Step 1: Count moos in original string
    for (int i = 0; i + 2 < N; i++) {
        int x, y;
        if (isMoo(s, i, x, y)) {
            count[x][y]++;
        }
    }

    // possible[x][y] = true if moo "xyy" can appear >= F times
    vector<vector<bool>> possible(26, vector<bool>(26, false));

    // Step 2: Check original string without corruption
    for (int x = 0; x < 26; x++) {
        for (int y = 0; y < 26; y++) {
            if (x != y && count[x][y] >= F) {
                possible[x][y] = true;
            }
        }
    }

    // Step 3: Try changing each position
    for (int i = 0; i < N; i++) {
        char original = s[i];

        for (char replacement = 'a'; replacement <= 'z'; replacement++) {
            if (replacement == original) continue;

            vector<pair<int, int>> removedMoos;
            vector<pair<int, int>> addedMoos;

            // Remove old moos affected by position i
            for (int start = i - 2; start <= i; start++) {
                if (start < 0 || start + 2 >= N) continue;

                int x, y;
                if (isMoo(s, start, x, y)) {
                    removedMoos.push_back({x, y});
                }
            }

            // Apply change
            s[i] = replacement;

            // Add new moos created by this change
            for (int start = i - 2; start <= i; start++) {
                if (start < 0 || start + 2 >= N) continue;

                int x, y;
                if (isMoo(s, start, x, y)) {
                    addedMoos.push_back({x, y});
                }
            }

            // Update counts
            for (auto moo : removedMoos)
                count[moo.first][moo.second]--;

            for (auto moo : addedMoos)
                count[moo.first][moo.second]++;

            // Check if any moo now reaches frequency F
            for (auto moo : addedMoos) {
                if (count[moo.first][moo.second] >= F) {
                    possible[moo.first][moo.second] = true;
                }
            }

            // Roll back changes
            for (auto moo : removedMoos)
                count[moo.first][moo.second]++;

            for (auto moo : addedMoos)
                count[moo.first][moo.second]--;

            s[i] = original;
        }
    }

    // Step 4: Collect results
    vector<string> answer;
    for (int x = 0; x < 26; x++) {
        for (int y = 0; y < 26; y++) {
            if (x != y && possible[x][y]) {
                string moo;
                moo += char('a' + x);
                moo += char('a' + y);
                moo += char('a' + y);
                answer.push_back(moo);
            }
        }
    }

    sort(answer.begin(), answer.end());

    // Step 5: Output
    cout << answer.size() << "\n";
    for (const string& m : answer) {
        cout << m << "\n";
    }

    return 0;
}
