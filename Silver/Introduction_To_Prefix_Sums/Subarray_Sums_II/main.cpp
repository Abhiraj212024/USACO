#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

	int n, x;
	cin >> n >> x;

	vector<int> arr(n+1, 0);

	for(int i{1}; i <= n; i++) cin >> arr[i];

	vector<int> prefix(n+1, 0);
	for(int i{1}; i <= n; i++){
		prefix[i] = prefix[i-1] + arr[i];
	}

	//create frequency map

	unordered_map<int, int> freq;
	freq[0] = 1;
	for(int i{1}; i <= n; i++){
		if(freq.find(prefix[i]) == freq.end()){
			freq[prefix[i]] = 1;
		}else{
			freq[prefix[i]] += 1;
		}
	}

	int total = 0;
	
	for(int i{1}; i <= n; i++){
		int a = prefix[i];
		int b = a - x;
		if(freq.find(b) != freq.end()){
			total += freq[b];
		}
	}

	cout << total << "\n";

	return 0;
}
