#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define LL long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n+1, 0);
        vector<LL> p(n+1, 0);
        for(int i{1}; i <= n; i++){
            a[i] = s[i-1] - '0';
            p[i] = p[i-1] + (LL)a[i];
        }

        unordered_map<LL, int> m;
        for(int i{}; i <= n; i++){
            LL temp = p[i] - (LL)i;

            if(m.find(temp) == m.end()){
                m[temp] = 1;
            }else{
                m[temp]++;
            }
        }
        LL count = 0;
        for(const auto& [_, c] : m){
            count += ((LL)c * (LL)(c-1)) / 2;
        }

        cout << count << "\n";
    }
    return 0;
}
