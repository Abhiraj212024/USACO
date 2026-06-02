#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(a <= 0) return b;
    if(b <= 0 ) return a;
    return gcd(b, a%b);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n; i++) cin >> a[i];

        int i = 0;
        int x = 0;
        while(i < n - i - 1){
            x = gcd(abs(a[i] - a[n-i-1]), x);
            i++;
        }

        cout << x << "\n";
    }
    return 0;
}