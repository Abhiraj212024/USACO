#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

pair<int, int> extract_window(const vector<int>& a, int k){
    int i{};
    int j{};
    int n = a.size();
    pair<int, int> p;
    int max_win_size = 0;
    while(i < n && j < n && i <= j){
        if(a[j] - a[i] > k) i++;
        else{
            if(j-i+1 > max_win_size){
                p.first = i;
                p.second = j;
                max_win_size = j-i+1;
            }

            if(j == n-1) break; // any can't make any futher improvements in size, can only decrease

            j++;
        }
    }

    return p;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N, 0);
    for(int i{}; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    pair<int, int> ans1 = extract_window(a, K);

    int len1 = ans1.second - ans1.first + 1;

    // do the second pass

    vector<int> b;
    for(int i = 0; i < N; i++){
        if(i >= ans1.first && i <= ans1.second) continue;
        b.push_back(a[i]);
    }

    pair<int, int> ans2 = extract_window(b, K);

    int len2 = ans2.second - ans2.first + 1;

    cout << len1 + len2 << "\n";

    return 0;
}