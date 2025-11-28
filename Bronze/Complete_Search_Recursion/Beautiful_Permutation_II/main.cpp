#include <iostream>

using namespace std;

int main(){

	int n;
	cin >> n;

	//note that the solution to this problem is fairly simple: for n >= 5 just print the odd numbers in increasing order and then the even numbers. For n = 4, the answer is 2 4 1 3. For n <= 3 solution does not exist

	if(n <= 3){
		cout << "NO SOLUTION\n";
	}else if(n == 4){
		cout << 2 << 4 << 1 << 3 << endl;
	}else{
		for(int i = 1; i <= n; i+=2){
			cout << i << " ";
		}
		for(int i = 2; i <= n; i+=2){
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}
