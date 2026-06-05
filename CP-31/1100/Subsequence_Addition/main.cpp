#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> c(n);
        for(int i = 0;i < n; i++) cin >> c[i];
        sort(c.begin(), c.end());

        if(c[0] != 1){
            cout << "NO\n";
            continue;
        }

        vector<ll> pref(n, 0);
        pref[0] = c[0];

        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + c[i];
        }
        int possible = true;
        for(int i = 1; i < n; i++){
            if(pref[i-1] < c[i]){
                possible = false;
                break;
            }
        }

        if(possible){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}