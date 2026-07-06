#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        // if all ai are greater than bi, then order doesn't matter and no need for sorting
        bool all_greater = true;
        for(int i = 0; i < n; i++){
            if(a[i] < b[i]){
                all_greater = false;
                break;
            }
        }

        if(all_greater){
            cout << accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0) << "\n";
            continue;
        }

        // now we need to make at least one change, which means now sort
        int minTime = c;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool possible = true;
        for(int i = 0; i < n; i++){
            if(a[i] < b[i]){
                possible = false;
                break;                
            }
            minTime += (a[i] - b[i]);
        }

        if(possible){
            cout << minTime << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
    return 0;
}