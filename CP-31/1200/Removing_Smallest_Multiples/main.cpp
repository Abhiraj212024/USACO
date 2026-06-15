#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long total_cost = 0;
        vector<bool> visited(n+1, false);
        for(int k = 1;k <= n; k++){
            int j = k;
            while(j <= n && s[j-1] == '0'){
                if(visited[j]){
                    j += k;
                    continue;
                }
                total_cost += k;
                visited[j] = true;

                j += k;
            }
        }

        cout << total_cost << "\n";
    }
    return 0;
}