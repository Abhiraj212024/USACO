#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> a_mod(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> a_mod[i];

        int l = 0;
        int r = 0;
        
        for(int i = 0;i < n; i++){
            // first mismatch
            if(a_mod[i] != a[i]){
                l = i;
                break;
            }
        }

        for(int i = n-1; i >= 0; i--){
            // last mismatch
            if(a_mod[i] != a[i]){
                r = i;
                break;
            }
        }

        // l and r are the minimum possible subarray and have to be included, expand sideways from them
        // a_mod[l..r] is sorted
        // move l to maximum in left position
        while(l >= 1 && a_mod[l-1] <= a_mod[l]){
            l--;
        }

        // move r to the maximum in right position
        while(r < n-1 && a_mod[r] <= a_mod[r+1]){
            r++;
        }

        cout << l+1 << " " << r+1 << "\n";
    }
    return 0;
}