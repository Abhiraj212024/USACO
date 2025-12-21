#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	
	for(int i{}; i < N; i++) cin >> arr[i];
	
	vector<int> sorted_arr = arr;
	sort(sorted_arr.begin(), sorted_arr.end());

	int swaps = 0;
	for(int i{}; i < N; i++){
		if(arr[i] != sorted_arr[i]) swaps++;
	}

	cout << swaps - 1 << endl;

	return 0;
}
