#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    vector<pair<int, int>> coords;
    int n, b;
    cin >> n >> b;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pair<int, int> buff = {x, y};
        coords.push_back(buff);
    }

    int ans = n;

    for(auto [x, _] : coords){
        vector<pair<int, bool>> byY;
        int tl=0, tr=0, bl=0, br = 0;
        for(auto [cx, cy] : coords){
            byY.push_back({cy, (cx < x+1)});
            if(cx < x+1) tl++;
            else tr++;
        }
        sort(byY.begin(), byY.end());
        for(auto [cy, is_left] : byY){
            if(is_left){tl--; bl++;}
            else{tr--; br++;}

            int worst = max({tl, tr, bl, br});
            ans = min(ans, worst);
        }
        
    }

    cout << ans << "\n";

    return 0;
}