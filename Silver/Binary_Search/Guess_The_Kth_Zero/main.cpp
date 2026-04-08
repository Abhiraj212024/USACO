#include <iostream>

using namespace std;

	int query(int r, int k) {
	int res;
	cout << "? " << 1 << " " << r << '\n';
	cin >> res;
	return r - res <= k;
}

int main() {
	int n, t, k;
	cin >> n >> t >> k;
	k--;

	int lo = 0;
	int hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (query(mid, k)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}

	cout << "! " << hi << '\n';
}