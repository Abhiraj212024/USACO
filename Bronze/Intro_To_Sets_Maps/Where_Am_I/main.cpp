#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main(){
	int N;
	cin >> N;
	string sequence{};
	cin >> sequence;

	//find smallest unique substring
	
	//go through each substring of length i (sliding window). Maintain a set for that length, even if you find one duplicate, then go to next one

	for(int k{1}; k < N; k++){
		int i = 0;
		int j = i+k;
		unordered_set<string> s;
		bool valid = true;
		while(j <= N){
			//processing
			string temp = sequence.substr(i, k);
			if(!s.insert(temp).second){
				valid = false;
				break;
			}
			i++;
			j++;
		}
		if(valid){
			cout << k << "\n";
			return 0;
		}
	}
	return 0;
}
