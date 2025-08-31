#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n{0};
    cin >> n;
    vector<int> r(n,0);
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }
    int min_collective_distance = INT_MAX;

    int S = 0;
    int cost0 = 0;

    for(int i = 0; i < n; i++){
        S += r[i];
        cost0 += r[i]*i;
    }

    int current = cost0;

    for(int i = 0; i < n; i++){
        // cost(k+1) = cost(k) - S + n*r[k]
        current = current - S + (n)*r[i];
        min_collective_distance = min(min_collective_distance, current);

    }

    cout << min_collective_distance << " ";

    return 0;
}