#include <iostream>
#include <vector>
#include <unordered_map>

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

	unordered_map<int, int> seen_remainder;

	int max_distance = INT_MIN;

	for(int i{1}; i <= N; i++){
		if(seen_remainder.find((prefix[i] % 7)) == seen_remainder.end()){
			seen_remainder[prefix[i]%7] = i;
		}

		//found a similar mod, the stored index is definitely smaller

		max_distance = max(max_distance, (i - seen_remainder[prefix[i] % 7]));

	}

	cout << max_distance << endl;

	return 0;
}
