#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> p(n+1, vector<int>(26, 0)); // p[i] stores the number of characters 
                                                              
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1];
        p[i][s[i-1] - 'a']++;
    }


    int q;
    cin >> q;

    while(q--){
        int l,r;
        cin >> l >> r;

        int n_unique = 0;
        for(int i = 0; i < 26; i++){
            if(p[r][i] - p[l-1][i]){
                n_unique++;
            }
        }

        if((l == r) || (n_unique >= 3) || (s[r-1] != s[l-1])){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }

    }
    return 0;
}
