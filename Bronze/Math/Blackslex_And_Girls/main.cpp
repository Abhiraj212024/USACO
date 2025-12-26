#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_all_same(const string& s){
	for(int i{1}; i < s.length(); i++){
		if(s[i] != s[i-1]) return 0;
	}
	return 1;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x, y;
		cin >> n >> x >> y;
		string s{};
		vector<int> p(n, 0);
		cin >> s;
		for(int i{}; i < n; i++) cin >> p[i];
		int sum_p = 0;
		for(int i{}; i < n; i++) sum_p += p[i];
		if((x+y) < sum_p){
			cout << "NO\n";
			continue;
		}
		if(is_all_same(s)){
			// either 0 or 1
			if(s[0] == '0'){
				// x >= y + n
				if(x >= (y+n)){
					cout << "YES\n";
					continue;
				}else{
					cout << "NO\n";
					continue;
				}
			}else{
				// y >= x + n
				if(y >= (x+n)){
					cout << "YES\n";
					continue;
				}else{
					cout << "NO\n";
					continue;
				}
			}
		}else{
			int a_sum = 0;
			int b_sum = 0;
			for(int i{}; i < n; i++){
				int bigger = (p[i] / 2) + 1;
				int smaller = p[i] - bigger;
				if(s[i] == '0'){
					a_sum += bigger;
					b_sum += smaller;
				}else{
					a_sum += smaller;
					b_sum += bigger;
				}
			}
			if((x >= a_sum) && (y >= b_sum)){
				cout << "YES\n";
				continue;
			}else{
				cout << "NO\n";
				continue;
			}
		}
	}
	return 0;
}
