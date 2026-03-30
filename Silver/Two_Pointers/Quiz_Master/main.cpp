#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int M = 1e5;

vector<int> factors[M+1];

int main(){

    // precompute factors
    for(int i = 1; i <= M; i++){
        for(int j = i; j <= M; j+=i) factors[j].push_back(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i{}; i < n; i++) cin >> a[i];

        // maintain an array of size m to keep track of count of divisibility
        vector<int> factor_count(m+2, 0);

        int st{0};
        int end{0};

        sort(a.begin(), a.end());

        int min_diff = INT_MAX;
        int topics_covered = 0;

        while(st < n){
            // add student
            while(end < m && topics_covered < m){
                for(int x : factors[a[end]]){
                    if(x <= m){
                        factor_count[x]++;
                        if(factor_count[x] == 1){ // covered for the first time
                            topics_covered++;
                        }
                    }
                }
                end++;
            }
            


            if(topics_covered == m) min_diff = min(min_diff, a[end-1] - a[st]);

            // remove student
            for(int x : factors[a[st]]){
                if(x <= m){
                    factor_count[x]--;
                    if(factor_count[x] == 0){ // topic not covered anymore
                        topics_covered--;
                    }
                }
            }

            st++;
        }

        cout << ((min_diff == INT_MAX) ? -1 : min_diff) << "\n";
    }
    
    return 0;
}