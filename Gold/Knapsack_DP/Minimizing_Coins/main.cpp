#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0;i < n; i++){
        cin >> c[i];
    }

    vector<int> possible(x+1, INT_MAX);
    possible[0] = 0;

    for(int i = 0; i < n; i++){
        if(c[i] <= x) possible[c[i]] = 1;
    }

    for(int i = 1; i <= x; i++){
        for(int k = 0; k < n; k++){
            if(i - c[k] >= 0 && possible[i - c[k]] < INT_MAX){
                possible[i] = min(possible[i], possible[i - c[k]] + 1);
            }
        }
    }

    if(possible[x] == INT_MAX){
        cout << -1 << "\n";
    }else{
        cout << possible[x] << "\n";
    }

    return 0;
}