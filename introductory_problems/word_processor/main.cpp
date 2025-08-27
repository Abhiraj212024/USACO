#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    cin.ignore();

    string sentence;
    getline(cin, sentence);

    int idx = 0;
    int scout = 0;
    int count = 0;

    while(scout < sentence.length()){
        while(count < k){
            if(!isspace(sentence[scout])) count++; 
            scout++;
        }
        if(!isspace(sentence[scout])){
            while(!isspace(sentence[scout])) scout--;
        }

        while(idx <= scout){
            cout << sentence[idx];
            idx++;
        }
        cout << "\n";
        count = 0;
    }

    while(idx <= scout){
        cout << sentence[idx];
        idx++;
    }

    return 0;
}