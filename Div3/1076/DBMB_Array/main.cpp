#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, s, x;
        cin >> n >> s >> x;

        int sum = 0;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            sum += temp;
        }

        if(sum == s){
            cout << "YES\n";
            continue;
        }

        if(((s - sum) >= x) && ((s-sum)%x == 0)){
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";

    }
    return 0;
}