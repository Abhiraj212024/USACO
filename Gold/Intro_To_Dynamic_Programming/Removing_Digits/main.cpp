#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cache;

vector<int> getDigits(int n){
    vector<int> ans;
    int temp = n;
    while(temp){
        ans.push_back(temp % 10);
        temp /= 10;
    }
    return ans;
}

int solve(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1; // subtract the number itself
    if(cache.find(n) != cache.end()) return cache[n];
    vector<int> digits = getDigits(n);

    int val = INT_MAX;
    for(const int& digit : digits){
        if(digit == 0) continue;
        int temp;
        if(cache.find(n - digit) != cache.end()){
            temp = cache[n-digit];
        }else{
            temp = solve(n - digit);
            cache[n-digit] = temp;
        }

        val = min(val, temp);
    }

    return 1 + val;
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}