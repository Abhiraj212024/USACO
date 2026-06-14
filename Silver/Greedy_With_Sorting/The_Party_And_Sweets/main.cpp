#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define ll long long
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> b(n);
    for(int i = 0;i < n; i++) cin >> b[i];
    vector<ll> g(m);
    for(int i = 0;i < m; i++) cin >> g[i];

    sort(b.begin(), b.end());
    long long b_sum = accumulate(b.begin(), b.end(), 0LL);

    bool possible = true;
    long long sum = 0;
    vector<ll> count(n, 0);

    for(int i = 0;i < m; i++){
        if(b[n-1] > g[i]){
            possible = false;
            break;
        }
        int idx = upper_bound(b.begin(), b.end(), g[i]) - b.begin();
        if(idx - 1 < 0){
            possible = false;
            break;
        }
        int curr = idx-1;
        while(curr > 0 && (count[curr] >= m-1)){
            if(b[curr] == g[i]) break;
            curr--;
        }
        sum += (b_sum - (b[curr]) + g[i]);
        if(b[curr] < g[i]) count[curr]++; // this number is greater than b[idx - 1]
        
    }

    for(int i = 0;i < n; i++){
        if(count[i] >= m){
            possible = false;
            break;
        }
    }

    if(possible){
        cout << sum << "\n";
    }else{
        cout << -1 << "\n";
    }

    return 0;
}