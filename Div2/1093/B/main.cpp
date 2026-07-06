#include <iostream>
#include <set>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        set<int> a;
        for(int i = 0; i < n; i++){
            int inp;
            cin >> inp;
            int k = (m - (inp + i + 1)%m)%m;
            a.insert(k);
        }

        cout << ((a.size() == m) ? "NO" : "YES") << "\n";
    }

    return 0;
}