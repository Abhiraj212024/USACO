#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int median = (n%2 == 0) ? (a[(n-1)/2] + a[n/2])/2 : a[n/2];


        int l = 0;
        int r = n-1;
        int calls = 0;
        while(l < r){
            if(a[l] != median || a[r] != median){
                l++;
                r--;
                calls++;
            }else{
                break;
            }
        }

        cout << calls << "\n";
    }
    return 0;
}