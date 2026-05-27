#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        int count = 0;
        unordered_set<char> uniques;
        
        for(int i = 0; i < n; i++){
            uniques.insert(s[i]);

            count += uniques.size();
        }

        cout << count << "\n";

    }
    return 0;
}