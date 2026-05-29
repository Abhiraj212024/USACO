#include  <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define ll long long
using namespace std;


int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0;
    int r = n-1;
    ll l_count = 1;
    ll r_count = 1;
    while(l < r && k > 0){

        if(a[l] == a[r]){
            break;
        }

        while(l + 1 < n && a[l] == a[l+1]){
            l_count++;
            l++;
        }

        while(r - 1 >= 0 && a[r] == a[r-1]){
            r_count++;
            r--;
        }

        if(l_count < r_count){
            ll total_ops = l_count * (a[l+1] - a[l]);
            if(k >= total_ops){
                k -= total_ops;
                l++;
                l_count++;
            }else{
                ll steps = k / l_count;
                a[l] += steps;
                k = 0;
            }
        }else{
            ll total_ops = r_count * (a[r] - a[r-1]);
            if(k >= total_ops){
                k -= total_ops;
                r--;
                r_count++;
            }else{
                ll steps = k / r_count;
                a[r] -= steps;
                k = 0;
            }
        }
    }

    cout << a[r] - a[l] << "\n";

    return 0;
}