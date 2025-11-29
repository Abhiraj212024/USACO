#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> numbers(n, 0);
	for(int i = 0; i < n; i++){
		cin >> numbers[i];
	}
	sort(all(numbers));
	int unique_count = 1;
	for(int i = 1; i < n; i++){
		if(numbers[i] != numbers[i-1]) unique_count++;
	}

	cout << unique_count << endl;
	return 0;
}
