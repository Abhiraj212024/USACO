#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool is_valid(int score, const unordered_set<int>& p, const unordered_set<int>& b){
	for(const int& bj : b){
		if(!(p.count(bj - score))) return false;
	}
	return true;
}

int main(){
	int k,n;
	cin >> k >> n;
	vector<int> marks(k, 0);
	unordered_set<int> p;
	int tracking_sum = 0;
	for(int i{}; i < k; i++){ //O(k)
		int ai;
		cin >> ai;
		tracking_sum += ai;
		p.insert(tracking_sum);
		marks[i] = ai;
	}
	
	unordered_set<int> b;
	for(int i{}; i < n; i++){ //O(n)
		int bi;
		cin >> bi;
		b.insert(bi);
	}

	unordered_set<int> possible_scores;
	for(const int& bj : b){ //O(nk)
		for(const int& pi : p){
			possible_scores.insert(bj - pi);
		}
	}
	int count = 0;
	for(const int& score : possible_scores){
		if(is_valid(score, p, b)){
			count++;
		}
	}

	cout << count << "\n";
	return 0;
}
