#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
    int N, K, B;
    cin >> N >> K >> B;
    unordered_set<int> s;
    for(int i{}; i < B; i++){
        int t;
        cin >> t;
        s.insert(t);
    }

    vector<int> p(N+1, 0);
    for(int i{1}; i <= N; i++){
       p[i] = (s.find(i) == s.end()) ? (p[i-1] + 0) : (p[i-1] + 1);
    }

    // find a subarray of size K with min sum
    int i = 1;
    int j = i+K-1;
    int min_sum = INT_MAX;
    while(j <= N){
        min_sum = min(min_sum, p[j] - p[i-1]);
        i++;j++;
    }

    cout << min_sum << "\n";
    return 0;
}
