#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;
int main(){
	vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
	unordered_map<string, int> milk;
	for(const string& cow : cows){
		milk[cow] = 0;
	}
	int n;
	cin >> n;
	for(int i{}; i < n; i++){
		string cow;
		int m;
		cin >> cow >> m;
		milk[cow] += m;
	}

	set<int> values;
	
	for(int i{}; i < cows.size(); i++){
		values.insert(milk[cows[i]]);
	}

	auto sec_smallest_it = values.begin();
	sec_smallest_it++;
	int second_smallest = *sec_smallest_it;

	for(const string& cow : cows){
		if(milk[cow] == second_smallest){
			cout << cow << "\n";
			return 0;
		}
	}
	return 0;
}
