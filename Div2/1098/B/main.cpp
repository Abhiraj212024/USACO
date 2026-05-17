#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        int d = min(abs(x1-x2), n - abs(x1-x2));
        if(n <= 3){
            cout << 1 << "\n";
        }else{
            cout << k + d << "\n";
        }
    }
    return 0;
}