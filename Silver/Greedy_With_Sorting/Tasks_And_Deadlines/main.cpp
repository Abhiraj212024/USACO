#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<long long, long long>> vec;

    for(int i = 0;i < n; i++){
        long long x, y;
        cin >> x >> y;
        vec.push_back({x, y});

    }
    
    sort(vec.begin(), vec.end());

    long long reward = 0;
    long long time = 0;

    for(const auto& [duration, deadline] : vec){
        time += duration;
        reward += (deadline - time);
    }

    cout << reward << "\n";

    return 0;
}
