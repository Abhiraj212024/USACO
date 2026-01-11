#include <iostream>
#include <vector>


using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = INT_MIN;
        for(int i{}; i < n; i++){
            int inp;
            cin >> inp;
            ans = max(ans, inp);
        }
        cout << ans << "\n";

    }
    return 0;
}
