#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n, 0);
    for(int i{}; i < n; i++) cin >> a[i];
    int sum = 0;
    int r = -1;
    int max_size = INT_MIN;    
    for(int l = 0; l < n; sum -= a[l++]){
        while((r+1 < n) && (sum + a[r+1] <= t)) sum += a[++r];
        max_size = max(max_size, r-l+1);
    }

    cout << max_size << "\n";
    return 0;
}
