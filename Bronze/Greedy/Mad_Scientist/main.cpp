#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	int N;
	cin >> N;
	string A;
	cin >> A;
	string B;
	cin >> B;

	int i = 0;
	int j = -1;

	int c = 0;
	while(i < N){
		if(A[i] != B[i]){
			j = i+1;
			while(A[j] != B[j]){
				j++;
			}
			j--;
			for(int a = i; a <= j; a++){
				if(B[a] == 'H'){
					B[a] = 'G';
				}else{
					B[a] = 'H';
				}
			}
			c++;
			i = 0;
			j = -1;
		}
		i++;
	}
	cout << c << endl;
	return 0;
}
