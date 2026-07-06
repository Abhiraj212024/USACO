#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        uint64_t count = 0;
        for(int i = 1; i <= n; i++){
            uint64_t k = (n/i);
            count += (k*k);
        }

        cout << count << "\n";

    }
    return 0;
}