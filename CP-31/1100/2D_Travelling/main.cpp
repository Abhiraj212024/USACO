#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, a, b;
        cin >> n >> k >> a >> b;

        a--;
        b--;

        vector<pair<ll, ll>> cities(n);
        for(int i = 0; i < n; i++){
            cin >> cities[i].first >> cities[i].second;            
        }
        
        ll min_dist_a = LLONG_MAX;

        for(int i = 0; i < k; i++){
            ll dist = abs(cities[i].first - cities[a].first) + abs(cities[i].second - cities[a].second);
            if(dist < min_dist_a){
                min_dist_a = dist;
            }    
        }

        ll min_dist_b = LLONG_MAX;


        for(int i = 0; i < k; i++){
            ll dist = abs(cities[i].first - cities[b].first) + abs(cities[i].second - cities[b].second);
            if(dist < min_dist_b){
                min_dist_b = dist;
            }    
        }
        ll dist_a_b = abs(cities[a].first - cities[b].first) + abs(cities[a].second - cities[b].second);

        cout << ((k > 0) ? min(min_dist_a + min_dist_b, dist_a_b) : dist_a_b) << "\n";
    }
    
    return 0;
}