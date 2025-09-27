#include <iostream>
#include <map>
#include <utility>
using namespace std;

bool is_between(int a1, int a2, int b){
    /* Checks if a1 < b < a2 */
    return ((b > a1) && (b < a2));
}

int main(){
    map<char, pair<int, int>> m;

    for(int i = 0; i < 52; i++){
        char letter;
        cin >> letter;
        if(m.find(letter) == m.end()){
            //not found then modify the first elemnt
            pair<int, int> buff = {i, -1};
            m[letter] = buff;
        }else{
            //already exists
            pair<int, int> buff = m[letter];
            buff.second = i;
            m[letter] = buff;
        }
    }

    int intersections = 0;

    for(int i = 0; i < 26; i++){
        char comp = 'A' + i;
        int a1 = m[comp].first;
        int a2 = m[comp].second;
        for(int j = i + 1; j < 26; j++){
            char check = 'A' + j;
            int b1 = m[check].first;
            int b2 = m[check].second;

            //cases 
            if(is_between(a1, a2, b1) ^ (is_between(a1, a2, b2))) intersections++;

        }
    }

    cout << intersections << "\n";

    return 0;
}