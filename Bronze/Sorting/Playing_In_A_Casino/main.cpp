#include <iostream>
#include <vector>

#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> transpose(int n, int m, const vector<vector<int>>& matrix){
	vector<vector<int>> ans(m, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans[j][i] = matrix[i][j];
		}
	}
	return ans;
}

int evaluate_testcase(int n, int m, vector<vector<int>> cards_t){//O(mnlogn)
	int sum = 0;
	for(int i = 0; i < m; i++){ //O(m)
		vector<int> column = cards_t[i];
		sort(all(column)); //(nlogn)
		vector<int> prefix_sum(n, 0); //prefix_sum[i] = prefix_sum[i-1] + column[i]
		prefix_sum[0] = column[0];
		for(int i = 1; i < n; i++){ //O(n)
			prefix_sum[i] = prefix_sum[i-1] + column[i];
		}
		//contibution of each column[i] : column[i] * (i) - (prefix_sum[i-1])
		int contribution = 0;
		for(int i = 1; i < n; i++){ //O(n)
			contribution += ((column[i]*i) - (prefix_sum[i-1]));
		}
		sum += contribution;
	}
	return sum;
}

int main(){

	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> cards(n, vector<int>(m, 0));
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cin >> cards[j][k];
			}
		}
		vector<vector<int>> trans = transpose(n, m, cards);
		cout << evaluate_testcase(n, m, trans) << endl;
	}

	return 0;
}
