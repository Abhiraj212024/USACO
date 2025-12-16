#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;

	vector<int> arr(n, 0);
	unordered_map<int, int> m;

	for(int i{}; i < n; i++){
		int in;
		cin >> in;
		arr[i] = in;
		m[in] = i;
	};

	for(int i{}; i < n; i++){
		auto it = m.find(x - arr[i]);
		if(it != m.end()){
			cout << i << "\t" << (*it).second << "\n";
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";


	return 0;
}
