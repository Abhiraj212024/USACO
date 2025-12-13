#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int>& arr, int target){
	int st = 0;
	int end = arr.size() - 1;

	while(st <= end){
		int mid = st + (end - st)/2;
		if(arr[mid] == target) return mid;
		if(arr[mid] > target){
			end = mid-1;
		}else{
			st = mid+1;
		}
	}
	return -1;
}


int main(){
	int n;
	cin >> n;
	vector<int> pos(n, 0);
	for(int i = 0; i < n; i++){
		cin >> pos[i];
	}

	vector<int> l(n, 0);
	vector<int> r(n, 0);

	sort(pos.begin(), pos.end());


	//L -> R pass
	for(int i = 0; i < n; i++){
		int t = 1;
		int count = 0;
		int curr = i;
		while(true){
			int min_limit = pos[curr] - t;
			int idx = binary_search(pos, min_limit);
			if(idx >= curr) break;
			if(idx == -1){
				t--;
				continue;
			}
			curr = idx;
			count++;
			t++;
		}
		l[i] = count;
	}

	// R -> L pass
	for(int i = n-1; i >= 0; i--){
		int t = 1;
		int count = 0;
		int curr = i;
		while(true){
			int max_limit = pos[curr] + t;
			int idx = binary_search(pos, max_limit);
			if(idx <= curr) break;
			if(idx == -1){
				t--;
				continue;
			}
			curr = idx;
			count++;
			t++;
		}
		r[i] = count;
	}

	int max_idx = 0;
	for(int i = 0; i < n; i++){
		max_idx = (l[max_idx] + r[max_idx] > l[i] + r[i]) ? max_idx : i;
	}

	cout << pos[max_idx] << "\n";

	return 0;
}
