#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	int N;
	cin >> N;
	set<pair<string, string>> s;
	for(int i{}; i < N; i++){
		string s1, s2;
		cin >> s1 >> s2;
		s1 = s1.substr(0, 2);
		pair<string, string> temp = {s1, s2};
		s.insert(temp);
	}

	int pairs = 0;
	for(const auto& p : s){
		pair<string, string> t = {p.second, p.first};
		if(s.count(t)) pairs++;
	}

	cout << pairs/2 << "\n";
	return 0;
}
