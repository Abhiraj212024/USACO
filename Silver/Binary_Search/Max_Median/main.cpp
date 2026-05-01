#include <iostream>
#include <vector>

using namespace std;

bool isPossible(const vector<int>& a, int k, int med){
    int n = a.size();
    vector<int> f(n, 0);
    f[0] = (a[0] >= med) ? 1 : -1;
    for(int i = 1; i < n; i++){
        if(a[i] >= med){
            f[i] = f[i-1] + 1;
        }else{
            f[i] = f[i-1] - 1;
        }
    }

    int mn = 0;
    int diff = 0;
    for(int i = k-1; i < n; i++){
        mn = (i-k >= 0) ? min(mn, f[i-k]) : min(mn, 0);
        diff = max(diff, f[i] - mn);
    }

    return diff > 0;
}

int main(){
    int n, k;
    cin >> n >> k;
    int hi = INT_MIN;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        hi = max(hi, a[i]);
    }
    int lo = 0;
    int valid = -1;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;

        if(isPossible(a, k, mid)){ // find last true
            valid = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }

    }

    cout << valid << "\n";
    return 0;
}