#include <iostream>
#include <vector>
#include <string>

using namespace std;





int main(){
    int n = 8;
    vector<string> board(n);
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    vector<int> permutations;
    for(int i = 0; i < n; i++){
        permutations.push_back(i);
    }

    int valid_configs = 0;

    do{
        //processing each config
        bool valid = true;
        for(int i = 0; i < n; i++){
            if(board[i][permutations[i]] == '*'){
                valid = false;
                break;
            }

            for(int j = 0; j < i; j++){
                if(abs(i - j) == abs(permutations[i] - permutations[j])) {
                    //diagonal clash
                    valid = false;
                    break;
                }
            }

            if(!valid) break;
        }

        if(valid) valid_configs++;
    } while(next_permutation(permutations.begin(), permutations.end()));


    cout << valid_configs << "\n";

    return 0;
}