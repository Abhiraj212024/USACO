#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N,Q;
	cin >> N >> Q;
	vector<int> ones(N+1, 0);
	vector<int> twos(N+1, 0);
	vector<int> threes(N+1, 0);
	for(int i{1}; i <= N; i++){
		int num;
		cin >> num;
		if(num == 1){
			ones[i] = 1;
		}else if(num == 2){
			twos[i] = 1;
		}else if(num == 3){
			threes[i] = 1;
		}
	}

	vector<int> one_prefix(N+1, 0);
	vector<int> two_prefix(N+1, 0);
	vector<int> three_prefix(N+1, 0);

	for(int i{1}; i <= N; i++){
		one_prefix[i] = one_prefix[i-1] + ones[i];
		two_prefix[i] = two_prefix[i-1] + twos[i];
		three_prefix[i] = three_prefix[i-1] + threes[i];
	}
	
	for(int i{}; i < Q; i++){
		int l, r;
		cin >> l >> r;
		cout << (one_prefix[r] - one_prefix[l-1]) << " " << (two_prefix[r] - two_prefix[l-1]) << " " << (three_prefix[r] - three_prefix[l-1]) << endl;
	}
	
	return 0;
}
