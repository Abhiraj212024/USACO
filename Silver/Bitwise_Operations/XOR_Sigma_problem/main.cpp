#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0;i < n; i++) cin >> a[i];

    ll ans = 0;

    for(int k = 0;k < 30; k++){
        vector<int> b(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++){
            b[i] = ((a[i] >> k) & 1);
            sum += b[i];
        }
        int n_ones = 0;
        int n_zeros = 1;
        vector<int> c(n, 0);
        c[0] = b[0];
        for(int i = 1;i < n; i++){
            c[i] = c[i-1] ^ b[i];
        }
        for(int i = 0; i < n; i++){
            if(c[i] == 0){
                n_zeros++;
            }else if(c[i] == 1){
                n_ones++;
            }
        }
        ans += (ll)(((ll)(n_ones * n_zeros) - sum)) * (ll)(1 << k);
    }

    cout << ans << "\n";

    return 0;
}