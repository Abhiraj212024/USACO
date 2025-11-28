#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> tokenize(string s){
	string word;
	vector<string> ans;
	for(int i = 0; i < s.length(); i++){
		if(s[i] != ' '){
			word+=s[i];
		}else{
			ans.push_back(word);
			word = "";
		}
	}
	if(word.length() != 0) ans.push_back(word);
	return ans;
}

pair<string, string> extract_constraint(string s){
	pair<string, string> ans;
	vector<string> split_sentence = tokenize(s);
	ans.first = split_sentence[0];
	ans.second = split_sentence[split_sentence.size() - 1];
	return ans;
}

int main(){

	int N;
	cin >> N;
	cin.ignore();
	vector<pair<string, string>> constraints;
	for(int i = 0; i < N; i++){
		string s;
		getline(cin, s);
		pair<string, string> constraint = extract_constraint(s);
		constraints.push_back(constraint);

	}
	vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
	do{
		bool is_valid = true;
		for(auto constraint : constraints){
			for(int i = 0; i < cows.size(); i++){
				string A = constraint.first;
				string B = constraint.second;
				if(cows[i] == A){
					bool left = (i > 0 && cows[i-1] == B);
					bool right = (i < 7 && cows[i+1] == B);
					if(!(left || right)){
						is_valid = false;
						break;
					}
				}
				if(cows[i] == B){
					bool left = (i > 0 && cows[i-1] == A);
					bool right = (i < 7 && cows[i+1] == A);
					if(!(left || right)){
						is_valid = false;
						break;
					}
				}

			}
			if(!is_valid) break;
		}
		if(!is_valid) continue; //invalid permutation, go to next 
		for(auto cow : cows){
			cout << cow << "\n";
		}
		break;
	}while(next_permutation(cows.begin(), cows.end()));
	return 0;
}
