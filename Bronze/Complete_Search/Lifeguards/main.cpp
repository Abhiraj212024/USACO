#include <iostream>
#include <utility>

using namespace std;

int main(){
    int time[1001] = {0};

    int n;
    cin >> n;

    vector<pair<int, int>> intervals;

    for(int i = 0; i < n; i++){
        pair<int, int> buff;
        cin >> buff.first >> buff.second;
        intervals.push_back(buff);
    }

    for(const auto& interval : intervals){
        int st=interval.first, end=interval.second;
        for(int i = st; i < end; i++){
            time[i]++;
        }
    }
    int max_time_covered = 0;
    int sum_time = 0;
    for(int i = 0; i < 1001; i++){
        sum_time = (time[i] > 0 ? sum_time + 1 : sum_time);
    }

    for(const auto& interval : intervals){
        int to_subtract = 0;
        int st=interval.first, end=interval.second;
        for(int i = st; i < end; i++){
            if((time[i] - 1) <= 0) to_subtract++; 
        }
        max_time_covered = max(max_time_covered, sum_time - to_subtract);
    }

    cout << max_time_covered << "\n";

    return 0;
}