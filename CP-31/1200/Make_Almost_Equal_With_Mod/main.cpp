#include <iostream>
#include <vector>
#include <unordered_set>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0;i < n; i++) cin >> a[i];
        ll ans = 0;
        for(int i = 1; i < 60; i++){
            unordered_set<ll> s;
            ll k = 1LL << i;
            for(const ll& num : a){
                s.insert(num % k);
            }
            if(s.size() == 2){
                ans = k;
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}