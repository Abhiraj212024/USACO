#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll, int>> a(n);
        vector<int> a_sorted;
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a_sorted.push_back(a[i].first);
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        vector<ll> pref_a_sorted(n, a[0].first);

        for(int i = 1; i < n; i++){
            pref_a_sorted[i] = pref_a_sorted[i-1] + a[i].first;
        }
        
        vector<int> ans(n);
        // largest element can absorb everyone
        ans[a[n-1].second] = n-1;

        for(int i = n-2; i >= 0; i--){
            if(pref_a_sorted[i] >= a[i+1].first){
                // if it can absorb the next element, it gets the next element's reach
                ans[a[i].second] = ans[a[i+1].second];
            }else{
                // otherwise it stops till i
                ans[a[i].second] = i;
            }
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}