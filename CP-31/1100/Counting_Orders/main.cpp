#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    const int m = 7 + 1e9;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        int l = 0;
        int r = n-1;

        long long mul = 1;
        for(l = 0; l < n; l++){
            while(r >= 0 && b[l] < a[r]) r--;
            // num elems = n-r-1
            int num_elems = n-r-1;
            num_elems -= l; // account for accounted elements

            mul = (mul * (num_elems % m)) % m;
        }

        cout << mul << "\n";
    }
    return 0;
}