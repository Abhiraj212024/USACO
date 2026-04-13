#include <iostream>
#include <vector>
#define LL long long
using namespace std;

LL count(LL x, int n){
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        ans += min(x/i, (LL)n);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    // median range = 1 , n^2


    LL l = 1;
    LL r = (LL)n * n;
    LL comp = (r + 1)/2;
    LL ans = -1;
    LL mid = l + (r-l)/2;
    while(l <= r){
        mid = l + (r-l)/2;
        LL x = count(mid-1, n) + 1;
        LL y = count(mid, n);

        if(comp >= x && comp <= y){
            ans = mid;
            break;
        }

        if(y < comp){
            // move right
            l = mid;
        }else{
            // move left
            r = mid;
        }
    }

    if(ans == -1) ans = mid;

    cout << ans << "\n";

    return 0;
}