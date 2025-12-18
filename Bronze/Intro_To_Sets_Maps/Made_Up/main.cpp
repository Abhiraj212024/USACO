#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> a(N, 0);
	vector<int> b(N, 0);
	vector<int> c(N, 0);

	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) cin >> b[i];
	for(int i = 0; i < N; i++) cin >> c[i];

	unordered_map<int, int> m;
	for(const int& ai : a){
		if(m.find(ai) == m.end()){
			m[ai] = 1;
		}else{
			m[ai]++;
		}
	}

	int ans = 0;
	for(const int& cj : c){
		ans += m[b[cj - 1]];
	}

	cout << ans << "\n";
	return 0;
}
