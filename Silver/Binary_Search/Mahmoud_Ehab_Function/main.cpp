#include <iostream>
#include <vector>
#include <algorithm>

#define LL long long

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<LL> a(n);
    vector<LL> b(m);
    
    for(int i{}; i < n; i++) cin >> a[i];
    for(int i{}; i < m; i++) cin >> b[i];
    vector<LL> c(m);
    for(int i = 0; i < m; i++){
        if(i % 2 == 0) c[i] = b[i];
        else c[i] = -b[i];
    }

    vector<LL> pref(m+1, 0);
    for(int i = 0; i < m; i++){
        pref[i+1] = pref[i] + c[i];
    }

    vector<LL> precomp;
    for(int j = 0; j <= m-n; j++){
        LL val = pref[j+n] - pref[j];
        if(j % 2) val = -val;
        precomp.push_back(val);
    }

    sort(precomp.begin(), precomp.end());

    LL a_sum = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) a_sum += a[i];
        else a_sum -= a[i];
    }

    auto it = lower_bound(precomp.begin(), precomp.end(), a_sum);

    LL ans = LLONG_MAX;

    if(it != precomp.end())
        ans = min(ans, abs(a_sum - *it));

    if(it != precomp.begin()){
        --it;
        ans = min(ans, abs(a_sum - *it));
    }

    cout << ans << "\n";

    while(q--){
        int l, r;
        LL x;
        cin >> l >> r >> x;
        // l and r and 1 indexed
        
        int n_odds = ((r+1)/2 - l/2);
        int n_evens = (r/2 - (l-1)/2);

        a_sum += (n_odds - n_evens) * x; 

        it = lower_bound(precomp.begin(), precomp.end(), a_sum);

        ans = LLONG_MAX;

        if(it != precomp.end())
            ans = min(ans, abs(a_sum - *it));

        if(it != precomp.begin()){
            --it;
            ans = min(ans, abs(a_sum - *it));
        }

        cout << ans << "\n";
    }

    return 0;
}