#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = (n * (n-1))/2;
        vector<int> b(l);
        for(int i = 0;i < l; i++) cin >> b[i];
        sort(b.begin(), b.end());
        vector<int> ans;
        int j = 0;
        while(n > 1 && j < l){
            ans.push_back(b[j]);
            j += n-1;
            n--;
        }
        ans.push_back(b[l-1]);

        for(const int& num : ans){
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}