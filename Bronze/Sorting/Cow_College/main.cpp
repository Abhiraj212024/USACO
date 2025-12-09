#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> fees(n, 0);
	for(int i = 0; i < n; i++){
		cin >> fees[i];
	}

	int max_idx = 0;
	sort(fees.begin(), fees.end());
	for(int i = 0; i < n; i++){
		int tuition = fees[i] * (n-i);
		max_idx = (fees[max_idx]*(n-max_idx) > tuition) ? max_idx : i;
	}
	cout << fees[max_idx]*(n-max_idx) << " " << fees[max_idx] << "\n";
	return 0;
}
