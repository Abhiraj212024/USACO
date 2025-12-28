#include <iostream>
#include <vector>
using namespace std;
int abs(int x){
	return (x >= 0) ? x : -1*x;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n, 0);
		for(int i = 0; i < n; i++) cin >> a[i];
		if(a[0] == -1 && a[n-1] == -1){
			a[0] = 0;
			a[n-1] = 0;
		}else if(a[0] == -1 && a[n-1] != -1){
			a[0] = a[n-1];
		}else if(a[0] != -1 && a[n-1] == -1){
			a[n-1] = a[0];
		}
		for(int i = 0; i < n; i++){
			if(a[i] == -1){
				a[i] = 0;
			}
		}
		cout << abs(a[0] - a[n-1]) << "\n";
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
