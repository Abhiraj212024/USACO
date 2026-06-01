#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;

        vector<vector<int>> stacks(3, vector<int>(n));
        vector<int> tops(3, 0);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++){
                cin >> stacks[i][j];
            }
        }
        int num = 0;
        while(num != x){
            int count = 0;
            for(int i = 0; i < 3; i++){
                if(tops[i] < n && ((stacks[i][tops[i]] | x) == x)){
                    count++;
                    num |= stacks[i][tops[i]];
                    tops[i]++;
                }
            }

            if(count == 0 && num != x){
                // can't move forward
                break;
            }
        }

        if(num != x){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }
    return 0;
}