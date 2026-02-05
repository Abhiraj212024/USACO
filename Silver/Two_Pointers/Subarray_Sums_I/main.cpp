#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n, 0);
    for(int i{}; i < n; i++) cin >> a[i];

    int r = -1;
    int sum = 0;
    int count = 0;
    for(int l = 0; l < n; l++){
        while((r+1 < n) &&  (sum + a[r+1] <= x)){
            sum += a[r+1];
            if(sum == x) count++;
            r++;
        }
        sum -= a[l];
    }

    cout << count << "\n";
    return 0;
}
