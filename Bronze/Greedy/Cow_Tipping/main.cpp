#include <iostream>
#include <vector>

using namespace std;

void toggle_rectangle(int row, int col, vector<vector<int>>& farm){
	for(int i{}; i <= row; i++){
		for(int j{}; j <= col; j++){
			farm[i][j] = !farm[i][j];
		}
	}
}

int main(){
	int N;
	cin >> N;
	vector<vector<int>> farm(N, vector<int>(N, 0));

	for(int i{}; i < N; i++){
		for(int j{}; j < N; j++) cin >> farm[i][j];
	}

	int count = 0;
	for(int i{N-1}; i >= 0; i--){
		for(int j{N-1}; j >= 0; j--){
			if(farm[i][j]){
				toggle_rectangle(i, j, farm);
				count++;
			}
		}
	}

	cout << count << endl;
	return 0;
}
