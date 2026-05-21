#include <iostream>
#include <climits>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n_coins, amount;
        cin >> n_coins >> amount;

        vector<int> coins(n_coins);
        for(int i = 0; i < n_coins; i++) cin >> coins[i];

        vector<int> values(amount+1, INT_MAX);
        values[0] = 0;
        for(const int& c : coins){
            for(int i = 1; i <= amount; i++){
                if(i - c < 0) continue;
                if(values[i-c] == INT_MAX) continue;
                values[i] = min(values[i], values[i-c]+1);
            }
        }

        cout << ((values[amount] == INT_MAX) ? -1 : values[amount]) << "\n";
    }

    return 0;
}
