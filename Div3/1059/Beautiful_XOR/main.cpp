#include <iostream>
#include <vector>
using namespace std;

int highestBit(int x){
    return 31 - __builtin_clz(x); // index of MSB
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        if(a == b){
            cout << 0 << "\n";
            continue;
        }

        if(highestBit(b) > highestBit(a)){
            cout << -1 << "\n";
            continue;
        }

        vector<int> ops;

        while(a != b){
            int k = highestBit(a^b); //highest different bit
            int x = (1 << k);

            //  x is guaranteed to be <= a
            ops.push_back(x);
            a ^= x;
        }

        cout << ops.size() << "\n";
        for(int i = ops.size()-1; i >= 0; i--){
            cout << ops[i] << " ";
        }
        cout << "\n";
        
   }
}
