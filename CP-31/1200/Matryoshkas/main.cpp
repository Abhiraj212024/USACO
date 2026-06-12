#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n; i++) cin >> a[i];

        map<int, int> freq;
        for(int i = 0;i < n; i++){
            freq[a[i]]++;
        }

        int count = 0;
        for(const auto& [elem, frequency] : freq){
            count += max((frequency - freq[elem - 1]), 0);
        }

        cout << count << "\n";
    }
    return 0;
}