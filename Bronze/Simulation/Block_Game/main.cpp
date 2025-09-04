#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//a = 97
int main(){
    int n;
    cin >> n;
    int ans[26] = {};
    for(int i = 0; i < n; i++){
        string a;
        string b;
        int countA[26] = {};
        int countB[26] = {};

        cin >> a >> b;

        for(char c : a){
            countA[((int)c) - 97]++;
        }

        for(char c : b){
            countB[((int)c) - 97]++;
        }

        for(int j = 0; j < 26; j++){
            ans[j] += max(countA[j], countB[j]);
        }
    }

    for(int i = 0; i < 26; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}