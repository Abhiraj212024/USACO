#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> p(n, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i == 0){
                p[0] = a[0];
            }else{
                p[i] = p[i-1] + a[i];
            }
        }
        ll maxDiff = 0;
        for(int k = 1; k <= (n >> 1); k++){
            if(n%k != 0) continue;
            
            ll curr_min = LLONG_MAX;
            ll curr_max = LLONG_MIN;

            int st = 1;
            while(st <= (n/k)){
                if(st == 1){
                    curr_min = min(curr_min, p[st*k - 1]);
                    curr_max = max(curr_max, p[st*k - 1]);
                }else{
                    curr_min = min(curr_min, p[st*k - 1] - p[(st-1)*k - 1]);
                    curr_max = max(curr_max, p[st*k - 1] - p[(st-1)*k - 1]);
                }
                st++;
            }

            maxDiff = max(maxDiff, curr_max - curr_min);
        }

        cout << maxDiff << "\n";
    }
    return 0;
}