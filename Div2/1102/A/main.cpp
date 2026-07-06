#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> b(n);
        for(int i = 0;i < n; i++) cin >> b[i];

        sort(b.rbegin(), b.rend());

        bool possible = true;

        for(int i = 2; i < n; i++){
            if(b[i] != (b[i-2] % b[i-1])){
                possible = false;
                break;
            }
        }

        if(possible){
            cout << b[0] << " " << b[1] << "\n";
        }else{
            cout << -1 << "\n";
        }

    }
    return 0;
}