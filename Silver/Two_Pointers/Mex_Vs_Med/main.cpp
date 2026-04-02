#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n;
		cin >> n;

		// stores position of integer
		vector<int> pos(n);

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			pos[x] = i;
		}

		// initialize left and right bounds for mex
		int left = pos[0], right = pos[0];
		ll res = 1;

		// mex represents the current mex left and right cover
		for (int mex = 1; mex < n; mex++) {
			int next_pos = pos[mex];

			// skip if next_pos is already between left and right
			if (left <= next_pos && next_pos <= right) { continue; }

			// Since we can create a valid subsegment for a given mex up until
			// size mex * 2, our max difference between left and right is mex * 2 - 1.
			int max_diff = mex * 2 - 1;

			if (next_pos < left) {
				for (; left > next_pos; left--) {
					int largest_right = min(left + max_diff, n - 1);
					// add all possible right bounds that don't change the
					// current mex
					res += max(largest_right - right + 1, 0);
				}
			} else {
				for (; right < next_pos; right++) {
					int smallest_left = max(right - max_diff, 0);
					// add all possible left bounds that don't change the
					// current mex
					res += max(left - smallest_left + 1, 0);
				}
			}
		}

		cout << res << '\n';
	}
}