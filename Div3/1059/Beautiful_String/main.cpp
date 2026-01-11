#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans;
        for(int i{1}; i <= n; i++){
            char inp;
            cin >> inp;
            if(inp == '0'){
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for(int i{}; i < ans.size(); i++) cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}
