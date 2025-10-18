#include <iostream>
#include <vector>
#include <map>
using namespace std;

int linear_search(const vector<pair<int, int>>& vec, int target){
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].first == target){
            return i;
        }
    }
    return -1;
}

/**
 * Vector containig pairs of people and corresponding drinking time of a milk
 * Map containing people who got sick at some time t in the party
 * Returns: Whether the milk can be bad or not
 */
bool can_be_bad(const vector<pair<int, int>>& p_t, const map<int, int> s_t){
    // A milk is never bad in one of the cases:
    // A person who got sick before drinking this milk
    // A person who never drank this milk and still got sick

    for(auto s : s_t){
        int person = s.first;
        int sick_time = s.second;
        int pos = linear_search(p_t, person);

        if(pos == -1) return false; //An person got sick after not drinking it
        if(p_t[pos].second > sick_time) return false; //A person was sick before drinking this milk
    }
    return true;
}

int main(){
    int N, M, D, S;
    cin >> N >> M >> D >> S;

    map<int, vector<pair<int, int>>> milk_map; // {m: {(p1, t1), (p2, t2), (p3, t3)...}}

    for(int i = 0; i < D; i++){
        int p, m, t;
        cin >> p >> m >> t;
        pair<int, int> temp = {p, t};
        vector<pair<int, int>> vec = {temp};

        if(milk_map.find(m) == milk_map.end()){
            milk_map[m] = vec;
        }else{
            milk_map[m].push_back(temp);
        }
    }

    map<int, int> sick_times;

    for(int i = 0; i < S; i++){
        int p, t;
        cin >> p >> t;
        sick_times[p] = t;
    }

    int required = INT_MIN;

    for(auto m : milk_map){
        if(can_be_bad(m.second, sick_times)){
            required = max(required, (int)m.second.size());
        }
    }

    cout << required << "\n";
    
    return 0;
}