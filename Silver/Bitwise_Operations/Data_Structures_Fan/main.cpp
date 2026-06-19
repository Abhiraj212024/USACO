#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n; i++){
            cin >> a[i];
        }
        string s;
        cin >> s;

        int g0 = 0;
        int g1 = 0;

        for(int i = 0;i < n; i++){
            if(s[i] == '0'){
                g0 ^= a[i];
            }else{
                g1 ^= a[i];
            }
        }

        vector<int> pref(n+1, 0);
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i-1] ^ a[i-1];
        }

        int q;
        cin >> q;

        while(q--){
            int tp;
            cin >> tp;
            if(tp == 1){
                int l, r;
                cin >> l >> r;
                g0 = pref[r] ^ pref[l-1] ^ g0;
                g1 = pref[r] ^ pref[l-1] ^ g1;
            }else{
                int g;
                cin >> g;
                if(g == 0){
                    cout << g0 << " ";
                }else{
                    cout << g1 << " ";
                }
            }
        }

        cout << "\n";
    }
    return 0;
}