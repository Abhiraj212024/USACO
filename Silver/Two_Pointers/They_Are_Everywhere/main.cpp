#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_set<char> unique_chars;
    vector<char> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        unique_chars.insert(s[i]);
    }
    int min_len = INT_MAX;
    unordered_map<char, int> caught;
    int l = 0;
    for(int r = 0; r < n; r++){
        if(caught.find(s[r]) == caught.end()) caught[s[r]] = 1;
        else caught[s[r]]++;

        while(l < r && caught[s[l]] > 1){
            l++;
            caught[s[l]]--;
        }

        if(caught.size() == unique_chars.size()){
            min_len = min(min_len, r-l+1);
        }
    }

    cout << min_len << "\n";
    return 0;
}