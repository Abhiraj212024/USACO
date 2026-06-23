#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> x[i];

    set<int> prev;
    
    for(int i = 1; i <= n; i++){
        vector<int> new_vals;
        for(const int& num : prev){
            new_vals.push_back(num + x[i]);
        }
        for(const int& num : new_vals){
            prev.insert(num);
        }
        prev.insert(x[i]);
    }

    cout << prev.size() << "\n";
    for(const int& num : prev){
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}