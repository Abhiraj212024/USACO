#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    vector<int> counts(n+1, 0);

    int base = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) base++;
    }
    counts[base]++;

    vector<vector<pair<int, int>>> pairs (2*n+5);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == b[j]){
                pairs[i+j].push_back({i, j});
            }
        }
    }

    for(int l = 0; l < n; l++){
        for(int r = l+1; r < n; r++){
            int c = 0; 
            for(auto [i, j] : pairs[l+r]){
                if(i >= l && i <= r && j >= l && j <= r){
                    c++;
                }
            }
            counts[c]++;
        }
    }

    for(int i = 0; i <= n; i++){
        cout << counts[i] << endl;
    }

    return 0;
}