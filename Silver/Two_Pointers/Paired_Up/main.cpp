#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> x(N, 0);
    vector<int> y(N, 0);
    unordered_map<int, int> m;
    for(int i{}; i < N; i++){
        cin >> x[i] >> y[i];
        m[y[i]] = x[i];
    }

    sort(y.begin(), y.end());

    for(int i {}; i < N; i++){
        x[i] = m[y[i]];
    }

    // now have sorted y and freq counts according to that

    int l = 0, r = N-1;
    int max_time = INT_MIN;
    while(l <= r){
        if(x[l] == 0){
            l++;
            continue;
        }
        if(x[r] == 0){
            r--;
            continue;
        }
        int min_freq = min(x[l], x[r]);
        if(l == r){
            x[l] -= min_freq;
        }else{
            x[l] -= min_freq;
            x[r] -= min_freq;
        }
        max_time = max(max_time, y[l] + y[r]);
        if(x[l] == 0) l++;
        if(x[r] == 0) r--;
    }

    cout << max_time << "\n";

    return 0;
}
