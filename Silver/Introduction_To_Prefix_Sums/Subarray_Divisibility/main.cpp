#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1, 0);
    vector<int> p(n+1, 0);
	for(int i{1}; i <= n; i++){
        cin >> a[i];
        p[i] = p[i-1] + a[i];
	}

    int count{};
    unordered_set<int> remainders;
    for(int i{1}; i <= n; i++){
        if(remainders.find(p[i] % n) == remainders.end()){
            remainders.insert(p[i] % n);
        }else{
            count++;
        }

    }
    cout << count << "\n";
	return 0;
}
