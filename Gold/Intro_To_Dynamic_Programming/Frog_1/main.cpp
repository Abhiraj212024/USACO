#include <iostream>
#include <climits>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> h(N, INT_MAX);
    for(int i = 0; i < N; i++) cin >> h[i];

    vector<int> cost(N, INT_MAX);
    cost[0] = 0;
    cost[1] = abs(h[1] - h[0]);
    for(int i = 2; i < N; i++){
        
        cost[i] = min(cost[i-1] + abs(h[i] - h[i-1]), cost[i-2] + abs(h[i] - h[i-2]));
    }
    cout << cost[N-1] << "\n";
    return 0;
}