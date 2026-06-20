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

    for(int i = 0;i < n; i++){
        for(int w = 0; w <= x; w++){
            if(w - c[i] >= 0){
                ways[w] += ways[w - c[i]];
                ways[w] %= MOD;
            }
        }
    }

    cout << ways[x] << "\n";

    return 0;
}