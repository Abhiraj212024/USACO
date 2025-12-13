#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n = 0;
	cin >> n;
	vector<int> a(n, 0);
	vector<int> b(n, 0);

	for(int i{}; i < n; i++){
		cin >> a[i];
	}
	for(int i{}; i < n; i++){
		cin >> b[i];
	}

	for(int i{}; i < n; i++){
		int n_occur = (i+1)*(n-i);
		a[i] = a[i] * n_occur;
	}

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	long sum = 0;
	for(int i{}; i < n; i++){
		sum += (long)(a[i] * b[i]);
	}

	cout << sum << "\n";
	return 0;
}
