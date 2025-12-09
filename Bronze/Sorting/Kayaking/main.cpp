#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> weights(2*n, 0);
	for(int i = 0; i < 2*n; i++){
		cin >> weights[i];
	}
	sort(all(weights));
	int min_instability = INT_MAX;
	for(int i = 0; i < 2*n; i++){
		for(int j = i+1; j < 2*n; j++){
			vector<int> used;
			for(int k = 0; k < 2*n; k++){
				if(k != i && k != j){
					used.push_back(weights[k]);
				}
			}
			if(used.size() == 0) continue;
			int instability = 0;
			for(int i = 0; i < used.size() - 1; i++){
				instability += (used[i+1] - used[i]);
			}
			min_instability = min(min_instability, instability);
		}
	}
	cout << min_instability << "\n";
	return 0;
}
