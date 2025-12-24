#include <iostream>
#include <vector>

using namespace std;

int abs(int x){
	return (x >= 0) ? x : (-1*x);
}

int compute_answer(const vector<int>& arr, int n){
	int sum = 0;
	for(int i = 0; i < n-1; i++){
		sum += abs(arr[i] - arr[i+1]);
	}

	int ans = INT_MAX;
	for(int i = 0; i < n; i++){
		int ldiff = 0;
		int rdiff = 0;
		if(i>=1){
			ldiff = arr[i-1] - arr[i];
		}
		if(i <= n-2){
			rdiff = arr[i] - arr[i+1];
		}
		int comp = (sum - abs(ldiff) - abs(rdiff));
		if(!(i == 0 || i == n-1)){
			comp += abs(ldiff + rdiff);
		}
		ans = min(ans, comp);
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		for(int j = 0; j < n; j++){
			cin >> arr[j];
		}
		cout << compute_answer(arr, n) << "\n"; 

	}
	return 0;
}
