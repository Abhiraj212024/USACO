#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n%2){
			cout << 0 << "\n";
			continue;
		}
		cout << (n/4) + 1 << "\n";
	}
	return 0;
}
