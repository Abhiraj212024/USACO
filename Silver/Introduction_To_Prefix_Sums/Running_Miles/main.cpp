#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> beauty(n, 0);
        vector<int> pref_max(n, 0);
        vector<int> suff_max(n, 0);

        for (int i = 0; i < n; i++){
            cin >> beauty[i];
            pref_max[i] = beauty[i]+i;
            suff_max[i] = beauty[i]-i;
        }

        for(int i = 1; i < n; i++){
            pref_max[i] = max(pref_max[i], pref_max[i-1]);
        }
        

        for(int i = n-2; i >= 0; i--){
            suff_max[i] = max(suff_max[i], suff_max[i+1]);
        }

        int max_val = INT_MIN;
        for(int i = 1; i < n-1; i++){
            max_val = max(max_val, pref_max[i-1] + beauty[i] + suff_max[i+1]);
        }

        cout << max_val << "\n";
    }
    return 0;
}
