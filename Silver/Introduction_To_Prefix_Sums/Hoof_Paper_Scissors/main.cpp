#include <iostream>

using namespace std;

int max_num(const vector<int>& vec){
	int max_elem = INT_MIN;
	for(const int& elem : vec){
		max_elem = (elem > max_elem) ? elem : max_elem;
	}
	return max_elem;
}

int main(){
	int N;
	cin >> N;

	vector<int> hooves(N+1, 0);
	vector<int> papers(N+1, 0);
	vector<int> scissors(N+1, 0);

	for(int i{1}; i <= N; i++){
		char inp;
		cin >> inp;
		if(inp == 'P'){
			papers[i] = papers[i-1] + 1;
		}else{
			papers[i] = papers[i-1];
		}
		if(inp == 'S'){
			scissors[i] = scissors[i-1] + 1;
		}else{
			scissors[i] = scissors[i-1];
		}
		if(inp == 'H'){
			hooves[i] = hooves[i-1] + 1;
		}else{
			hooves[i] = hooves[i-1];
		}

	}
	
	int max_wins = 0;

	for(int i{1}; i <= N; i++){
		vector<int> lesser = {hooves[i], scissors[i], papers[i]};
		vector<int> bigger = {(hooves[N] - hooves[i-1]), (scissors[N] - scissors[i-1]), (papers[N] - papers[i-1])};
		int wins_lesser = max_num(lesser);
		int wins_bigger = max_num(bigger);
		max_wins = max(max_wins, wins_bigger + wins_lesser);
	}

	cout << max_wins << endl;

	return 0;
}
