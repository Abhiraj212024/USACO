#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> cows;

	for(int i = 0; i < n; i++){
		pair<int, int> temp;
		int a, b;
		cin >> a >> b;
		temp.first = a;
		temp.second = b;
		cows.push_back(temp);
	}

	sort(cows.begin(), cows.end());

	int time = 0;

	for(auto cow : cows){
		int arrival = cow.first;
		int processing = cow.second;
		if(time < arrival){
			time = arrival + processing;
		}else{
			time += processing;
		}
	}
	cout << time << "\n";

	return 0;
}
