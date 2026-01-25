#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define LL long long

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vector<int> prefix(n+1, 0);
        for(int i = 1; i <= n; i++){ // stores the swords required uptil index i
            prefix[i] = prefix[i-1] + b[i-1];
        }

        sort(a.begin(), a.end());

        LL max_score = LLONG_MIN;
        for(int i = 0; i < n; i++){
            if((i > 0) && (a[i] == a[i-1])) continue; // the best possible case for that x has already been counted
            int x = a[i];
            int available_swords = n-i;

            int levels_to_complete = upper_bound(prefix.begin(), prefix.end(), available_swords) - prefix.begin() - 1;

            LL score = 1LL * x * levels_to_complete;

            max_score = max(max_score, score);
        }

        cout << max_score << "\n";

    }
    return 0;
}