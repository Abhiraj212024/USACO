#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i{}; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    while(q--){
        int a, b;
        cin >> a >> b;
        int lb = lower_bound(arr.begin(), arr.end(), a) - arr.begin();

        int up = upper_bound(arr.begin(), arr.end(), b) - arr.begin();

        cout << up - lb << "\n";
    }
    return 0;
}