#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n; i++) cin >> a[i];

        int maxTime = 0;

        for(int i = 1;i < n; i++){
            if(a[i] < a[i-1]){
                int target = a[i-1] - a[i];
                a[i] = a[i-1];
                int leading_zeros = __builtin_clz(target);
                int time = 32 - leading_zeros;
                maxTime = max(maxTime, time);
            }
        }

        cout << maxTime << "\n";
    }
    return 0;
}