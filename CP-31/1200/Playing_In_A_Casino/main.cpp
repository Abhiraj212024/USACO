#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n, vector<int>(m, 0));
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> c[i][j];
            }
        }

        long long total_cost = 0;
        for(int i = 0; i < m; i++){
            vector<long long> v(n, 0);
            vector<long long> pref(n, 0);
            for(int j = 0; j < n; j++){
                v[j] = (long long)(c[j][i]);
            }
            sort(v.begin(), v.end());
            pref[0] = v[0];
            for(int j = 1; j < n; j++){
                pref[j] = pref[j-1] + v[j];
            }
            for(int j = n-1; j >= 1; j--){
                total_cost += ((j * v[j]) - pref[j-1]);
            }
        }

        cout << total_cost << "\n";
    }
    return 0;
}