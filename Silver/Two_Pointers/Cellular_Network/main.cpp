#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for(int i{}; i < n; i++) cin >> a[i];
    for(int i{}; i < m; i++) cin >> b[i];

    int max_r = INT_MIN;
    // Binary Search Approach (nlogn)
 /*   for(int i{}; i < n; i++){
        int tower_right = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int tower_left = tower_right - 1;
        int min_dist = INT_MAX;
        if((tower_right < m) && (b[tower_right] >= a[i])){
            min_dist = min(min_dist, b[tower_right] - a[i]);
        }
        if(tower_left >= 0 && (b[tower_left] <= a[i])){
            min_dist = min(min_dist, a[i] - b[tower_left]);
        }
        max_r = max(max_r, min_dist);
    }
*/

    // Two Pointers Approach (n)
    
    vector<int> dist(n, 0);
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j+1 < m && b[j+1] <= a[i]) j++;
        dist[i] = abs(a[i] - b[j]);
    }

    j = m-1;
    for(int i = n-1; i >= 0; i--){
        while(j-1>=0 && b[j-1] >= a[i]) j--;
        dist[i] = min(dist[i], abs(b[j] - a[i]));
    }

    for(int i = 0; i < n; i++) max_r = max(max_r, dist[i]);
    cout << max_r << "\n";
    return 0;
}
