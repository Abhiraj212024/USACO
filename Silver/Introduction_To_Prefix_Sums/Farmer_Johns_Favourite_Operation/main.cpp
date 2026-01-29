#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#define LL long long

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int N, M;
        cin >> N >> M;
        vector<LL> a(N, 0);
        for(int i{}; i < N; i++) cin >> a[i];

        vector<LL> b(N, 0);
        for(int i{}; i < N; i++) b[i] = a[i] % M;

        sort(b.begin(), b.end());

        vector<LL> c(2*N, 0);
        for(int i{}; i < N; i++){
            c[i] = b[i];
            c[i+N] = b[i] + M; 
        }

        vector<LL> p(2*N+1, 0);
        for(int i{1}; i <= 2*N; i++){
            p[i] = p[i-1] + c[i-1];
        }

        LL min_cost = LLONG_MAX;

        for(int l = 0; l < N; l++){
            int r = l+N-1;
            int mid = l + (N/2);
            LL l_cost = (c[mid] * (mid - l)) - (p[mid] - p[l]);
            LL r_cost = (p[r+1] - p[mid+1]) - (c[mid] * (r-mid));
            LL cost = l_cost + r_cost;
            min_cost = min(min_cost, cost);
        }
        cout << min_cost << "\n";
    }
    return 0;
}
