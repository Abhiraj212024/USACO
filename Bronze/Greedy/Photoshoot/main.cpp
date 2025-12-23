#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	string order{};
	cin >> order;

	int count = 0;
	// starting from back
	for(int i = n-2; i >= 0; i-=2){
		if((order[i] == 'G' && order[i+1] == 'H') && (count % 2 == 0)) count++;
		if((order[i] == 'H' && order[i+1] == 'G') && (count % 2 == 1)) count++;
	}

	cout << count << endl;
	return 0;
}
