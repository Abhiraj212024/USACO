#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> arr(N+1, 0);
	vector<long long> prefix(N+1, 0);

	for(int i{1}; i <= N; i++){
		cin >> arr[i];
		prefix[i] = prefix[i-1] + static_cast<long long>(arr[i]);
	}

	// apply sliding window
	int win_size = N-1;
	while(win_size > 0){

		int i = 1;
		int j = i+win_size;
		bool found = false;

		while(j <= N){
			long long subarray_sum = prefix[j] - prefix[i];
			if(subarray_sum % 7 == 0){
				found = true;
				break;
			}
			i++;
			j++;
		}

		if(found) break;

		win_size--;
	}

	cout << win_size << endl;
	return 0;
}
