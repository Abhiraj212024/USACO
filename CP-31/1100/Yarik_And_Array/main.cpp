#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int maxSum = a[0];
        int sum = a[0];
        for(int i = 1; i < n; i++){
            if(abs(a[i]) % 2 == abs(a[i-1]) % 2){
                // reset
                sum = 0;                
            }

            if(sum < 0){
                sum = a[i];
            }else{
                sum += a[i];
            }

            maxSum = max(maxSum, sum);
        }

        cout << maxSum << "\n";
    }
}