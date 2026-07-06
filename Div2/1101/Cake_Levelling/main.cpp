#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        ll min_val = LLONG_MAX;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            min_val = min(min_val, a[i]);
        }

        
        ll current_sum = 0;
        ll current_min = a[0];

        for(int i = 0; i < n; i++){
            current_sum += a[i];
            current_min = min(current_min, current_sum / (i+1));

            cout << current_min << " ";
        }
        
        cout << "\n";

    }
    return 0;
}