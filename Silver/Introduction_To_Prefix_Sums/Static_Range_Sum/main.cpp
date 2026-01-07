#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, Q;
	cin >> N >> Q;
	vector<int> arr(N, 0);
	for(int i{}; i < N; i++) cin >> arr[i];
	vector<int> prefix_sum(N, 0);
	int sum = 0;
	for(int i{0}; i < N; i++){
		prefix_sum[i] = sum + arr[i];
		sum += arr[i];
	}

	for(int i{}; i < Q; i++){
		int l, r;
		cin >> l >> r;
		cout << prefix_sum[r-1] - prefix_sum[l] + arr[l] << endl;
	}
	return 0;
}
