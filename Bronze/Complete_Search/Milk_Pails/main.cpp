#include <iostream>

using namespace std;

int main(){

    int x, y, m;
    cin >> x >> y >> m;

    int max_x = (m/x);
    int max_y = (m/y);

    int max_milk = INT_MIN;

    for(int i = 0; i < max_x; i++){
        for(int j = 0; j < max_y; j++){
            int milk = i*x + j*y;
            if(milk > m) break;
            max_milk = max(max_milk, milk);
        }
        if(max_milk == m) break;
    }

    cout << max_milk << "\n";

    return 0;
}