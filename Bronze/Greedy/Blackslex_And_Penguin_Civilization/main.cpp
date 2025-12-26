#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int popcount(int z){ // O(logn)
	int count = 0;
	if(!z) return 0;
	while(z){
		count += (z & 1);
		z >>= 1;
	}
	return count;
}

int main(){
	int t;
	cin >> t;
	for(int j = 0; j < t; j++){
		int n;
		cin >> n;
		vector<int> temp;
		int max_exp = (1 << n);
		for(int i = 0; i < max_exp; i++){
			temp.push_back(i);
		}
		sort(temp.begin(), temp.end(), [](int x, int y){
			int px = popcount(x);
			int py = popcount(y);

			if(px != py) return (px > py);
			return (x < y);
		});

		for(const int& elem : temp){
			cout << elem << " ";
		}
		cout << "\n";
	}
	return 0;
}
