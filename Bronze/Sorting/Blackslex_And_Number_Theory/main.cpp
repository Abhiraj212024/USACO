#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr.begin(), arr.end());
		int k = max(arr[0], arr[1] - arr[0]);

		cout << k << "\n";
	}
	return 0;
}
