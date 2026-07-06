#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int> c(26, 0);
        for(int i = 0; i < k; i++) cin >> c[i];

        // at least two equal bigrams
        // at least 2 elements with greater than 1 count or one element greater than 3

        bool possible = false;
        int g2 = 0;
        for(int i = 0; i < k; i++){
            if(c[i] >= 2) g2++;
            if(c[i] >= 3){
                possible = true;
                break;
            }
        }

        if(g2 > 1 || possible){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}