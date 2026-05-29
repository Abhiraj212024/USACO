#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

bool check(const vector<int>& packmen, deque<int> food, int time){
    for(const int& p : packmen){
        // will have to eat the left ones

        if(food[0] < p && p - food[0] > time) return false;
        
        vector<int> have_to_eat;
        while(!food.empty() && food[0] < p){
            have_to_eat.push_back(food[0]);
            food.pop_front();
        }


        if(have_to_eat.empty()){
            // can only go right no need to go left
            while(!food.empty() && food[0] - p <= time) food.pop_front();

            if(food.empty()) return true;
        }else{
            int left_time = p - have_to_eat[0];

            // going left first
            int right_free_time = time - 2*left_time;
            int left_first = -1;
            while(left_first + 1 < food.size() && food[left_first + 1] - p <= right_free_time) left_first++;

            // goinf right first
            right_free_time = time - left_time;
            int right_first = -1;
            while(right_first + 1 < food.size() && (food[right_first + 1] - p)*2 <= right_free_time) right_first++;

            // take the maximum
            for(int i = 0; i <= max(left_first, right_first) && !food.empty(); i++) food.pop_front();

        }
        if(food.empty()) return true;
    }
    return food.empty();
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> packmen;
    deque<int> food;

    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        if(c == 'P'){
            packmen.push_back(i);
        }else if(c == '*'){
            food.push_back(i);
        }
    }

    int l = 0;
    int r = INT_MAX-5;
    while(l < r){
        int mid = l + (r-l)/2;

        if(check(packmen, food, mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }

    cout << l << "\n";
    return 0;
}