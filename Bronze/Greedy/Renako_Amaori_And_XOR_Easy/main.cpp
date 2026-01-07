#include <iostream>
#include <vector>
using namespace std;

bool is_satisfied(int ones){
	if(ones % 2 == 0) return false;
	return true;
}

// for the hard part of this problem, replace each input element x with x % 2

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			a[i] = x%2; // modification done for hard
		}
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			b[i] = x%2; // modification done for hard
		}

		int a_one = 0;
		int b_one = 0;
		for(int i = 0; i < n; i++){
			if(a[i]){
				a_one++;
			}
			if(b[i]){
				b_one++;
			}
		}

		if(is_satisfied(a_one) && is_satisfied(b_one)){
			cout << "Tie\n";
			continue;
		}
		for(int i = 0; i < n; i++){
			if(i%2 == 0){ //A's chance (0 indexed)
				if(is_satisfied(a_one) || (a[i] == b[i])) continue;
				if(a[i]){
					//decrease 1 increase 0
					a_one--;b_one++;
				}else{
					//increase 1 decreas 0
					a_one++;b_one--;
				}
			}else{ // B's chance
				if(is_satisfied(b_one) || (a[i] == b[i])) continue;
				if(b[i]){
					//decrease 1 increase 0
					b_one--;a_one++;
				}else{
					//increase 1 decreas 0
					b_one++;a_one--;
				}
			}
		}

		if(is_satisfied(a_one) && !is_satisfied(b_one)){
			cout << "Ajisai\n";
		}else if(!is_satisfied(a_one) && is_satisfied(b_one)){
			cout << "Mai\n";
		}else{
			cout << "Tie\n";
		}
	}
	return 0;
}
