#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, K;
	cin >> N >> K;

	vector<int> d(N, 0);
	for(int i{}; i < N; i++) cin >> d[i];

	long long min_amount = 0; // for day 1

	int i = 0;
	int j = 1;

	while(j < N){
		//is it better to extend subsciption or stay?
		if((d[j] - d[i] + 1 + K) < (1 + K) * (j-i+1)){
			//extend
			min_amount+= (d[j] - d[i] + 1 + K);
			j++;
		}else{
			//stay
			min_amount+= (1+K) * (j-i+1);
			i = j+1;
			j = i+1;
		}
	}

	cout << min_amount << "\n";
	return 0;
}

