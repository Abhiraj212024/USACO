#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i = 0;i < n; i++){
            for(int j = 0;j < n; j++){
                cin >> a[i][j];
            }
        }
        int ops = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] != a[n-i-1][n-j-1]) ops++;
            }
        }
        ops /= 2;
        
        if(ops > k){
            cout << "NO\n";
        }else if(ops == k){
            cout << "YES\n";
        }else{
            int temp = k - ops;
            if(temp % 2 == 0) cout << "YES\n";
            else{
                if(n%2 == 1) cout << "YES\n";
                else cout << "NO\n";
            }
        }

    }
    return 0;
}