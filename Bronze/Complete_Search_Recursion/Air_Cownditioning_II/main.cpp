#include <iostream>
#include <vector>
using namespace std;

void compute_permutations(int k, int n, vector<int>& current_combination, vector<vector<int>>& res){
	if(k == n){ 
		res.push_back(current_combination);
		return;
	}
	// first keep the current index 0
	current_combination[k] = 0;
	compute_permutations(k+1, n, current_combination, res);

	//change it to 1
	current_combination[k] = 1;
	compute_permutations(k+1, n, current_combination, res);


}

vector<vector<int>> permutations(int n){
	vector<vector<int>> results;
	vector<int> current_combination(n, 0);
	int k = 0;
	compute_permutations(k, n, current_combination, results);
	return results;
}

int main(){

	int N,M;
	cin >> N >> M;
	
	//define the array to store the required cooling for each stall
	int c[102] = {0}; //102 to avoid rounding errors

	for(int i = 0; i < N; i++){
		int si,ti,ci;
		cin >> si >> ti >> ci;
		for(int j = si; j <= ti; j++){
			c[j] = ci;
		}
	}

	//enter step 2: generate permutations of AC's
	vector<vector<int>> data;
	for(int i = 0; i < M; i++){
		int ai,bi,pi,mi;
		cin >> ai >> bi >> pi >> mi;
		data.push_back({ai, bi, pi, mi});
	}
	int min_cost = INT_MAX;
	vector<vector<int>> perms = permutations(M);
	for(auto perm : perms){ //2^M
		int temp_arr[102] = {0};
		bool is_valid = true;
		// scan through to find ones
		for(int i = 0; i < M; i++){
			if(perm[i]){
				for(int j = data[i][0]; j <= data[i][1]; j++){
					temp_arr[j] += data[i][2];
				}
			}
		}
		for(int i = 0; i < 102; i++){
			if(c[i] > temp_arr[i]){
				is_valid = false;
				break;
			}
		}
		if(!is_valid) continue; //go to next for invalid iterations
		int cost = 0;
		//valid permutation: compute cost
		for(int i = 0; i < M; i++){
			cost += (perm[i] * data[i][3]);
		}
		min_cost = min(min_cost, cost);	
	}	
	cout << "Minimum Cost: " << min_cost << "\n";
	return 0;
}
