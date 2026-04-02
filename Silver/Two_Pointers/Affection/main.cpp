#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    while(q--){
        int m;
        char c;
        cin >> m >> c;

        int l = 0, count = 0, ans = 0;
        for(int r = 0; r < n; r++){
            if(s[r] != c) count++;
            while(count > m){
                if(s[l] != c) count--;
                l++;
            }

            ans = max(ans, r-l+1);
        }

        cout << ans << "\n";
    }
    return 0;
}