#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n,0);
    for(int i = 0;i < n; i++) cin >> c[i];

    vector<ll> ways(x+1, 0);

    ways[0] = 1;

    for(int i = 1; i <= x; i++){
        for(int k = 0; k < n; k++){
            if(i - c[k] >= 0){
                ways[i] += ways[i - c[k]];
                if(ways[i] >= MOD){
                    ways[i] -= MOD;
                }
            }
        }
    }

    cout << ways[x] << "\n";

    return 0;
}