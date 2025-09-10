#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<vector<char>> store;

    for(int i = 0; i < 3; i++){
        char c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        vector<char> temp = {c1, c2, c3};
        store.push_back(temp);
    }

    int singles = 0;
    int doubles = 0;

    //check singles

    for(int i = 0; i < 3; i++){

        //check row

        bool temp{true};
        char last = store[i][0];
        for(int j = 1; j < 3; j++){
            temp &= (last == store[i][j]);
            last = store[i][j];
        }
        if(temp){
            singles += 1;
        }

        //check column

        temp = true;
        last = store[0][i];
        for(int j = 1; j < 3; j++){
            temp &= (last == store[j][i]);
            last = store[j][i];
        }

        if(temp){
            singles += 1;
        }

    }

    //check diagonals
    if(store[0][0] == store[1][1] && store[1][1] == store[2][2]){
        singles+=1;
    }
    if(store[0][2] == store[1][1] && store[1][1] == store[2][0]){
        singles+=1;
    }

    //check doubles

    for(int i = 0; i < 3; i++){
        //rows

        if((store[i][0] == store[i][1] || store[i][0] == store[i][2]) && !(store[i][0] == store[i][1] && store[i][1] == store[i][2])){
            doubles++;
        }
        //cols

        if((store[0][i] == store[1][i] || store[0][i] == store[2][i]) && !(store[0][i] == store[1][i] && store[1][i] == store[2][i])){
            doubles++;
        }
    }

    //diagonals
    if((store[0][0] == store[1][1] || store[1][1] == store[2][2]) && !(store[0][0] == store[1][1] && store[1][1] == store[2][2])){
        doubles++;
    }
    
    //diagonals
    if((store[0][2] == store[1][1] || store[1][1] == store[2][0]) && !(store[0][2] == store[1][1] && store[1][1] == store[2][0])){
        doubles++;
    }
    
    cout << singles << "\n" << doubles << "\n";

    return 0;
}