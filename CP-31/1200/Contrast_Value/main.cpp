#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n; i++){
            cin >> a[i];
        }

        // remove any duplicates
        vector<int> unique_a;
        for(int i = 0; i < n; i++){
            if(unique_a.empty() || unique_a.back() != a[i]){
                unique_a.push_back(a[i]);
            }
        }

        if(unique_a.size() == 1){
            cout << 1 << "\n";
            continue;
        }

        if(unique_a.size() == 2 && unique_a[0] == unique_a[1]){
            cout << 1 << "\n";
            continue;
        }

        int len = unique_a.size(); // always keep first and last
        for(int i = 1; i < unique_a.size()-1; i++){
            if(abs(unique_a[i-1] - unique_a[i]) + abs(unique_a[i] - unique_a[i+1]) == abs(unique_a[i-1] - unique_a[i+1])){
                len--;
            }
        }

        cout << len << "\n";
    }
    return 0;
}