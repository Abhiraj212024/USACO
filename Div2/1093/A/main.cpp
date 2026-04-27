#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> count(103, 0);
        vector<int> a(n, 0);
        for(int i{}; i < n; i++){
            cin >> a[i];
            count[a[i]]++;
        }

        sort(a.rbegin(), a.rend());

        // check for duplicates
        bool has_dups = false;
        for(int i = 0; i < count.size(); i++){
            if(count[i] > 1){
                has_dups = true;
                break;
            }
        }

        if(has_dups){
            cout << -1 << "\n";
        }else{
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}