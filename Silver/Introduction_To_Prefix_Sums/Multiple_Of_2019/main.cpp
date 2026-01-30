#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define LL long long

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<LL> p(n+1, 0);
    LL mul_ten = 1;
    for(int i = n-1; i >= 0; i--){
        int num = s[i] - '0';
        p[i] = ((LL)(num*mul_ten + p[i+1])) % 2019;
        mul_ten *= 10;
    }

    unordered_map<LL, int> m;
    m[0] = 1;
    for(int i = 0; i < n; i++){
        if(m.find(p[i]) == m.end()){
            m[p[i]] = 1;
        }else{
            m[p[i]] += 1;
        }
    }
    int total = 0;
    for(const auto& couple : m){
        total += ((LL)((couple.second) * (couple.second - 1)))/2;
    }
    cout << total;
    return 0;
}