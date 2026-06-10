#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i = 0;
	int j = 0;
	int ans = 0;
	while (i < n && j < m) {
		// Found a suitable apartment for the applicant
		if (abs(a[i] - b[j]) <= k) {
			i++;
			j++;
			ans++;
		} else {
			// If the desired apartment size of the applicant is too big,
			// move the apartment pointer to the right to find a bigger one
			if (a[i] - b[j] > k) {
				j++;
			}
			// If the desired apartment size is too small,
			// skip that applicant and move to the next person
			else {
				i++;
			}
		}
	}

	cout << ans << endl;
}