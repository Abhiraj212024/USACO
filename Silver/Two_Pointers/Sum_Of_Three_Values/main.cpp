#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        m[a[i]] = i + 1;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        int l = 0;
        int r = n-1;
        int target = x-a[i];

        while(l != r){
            if(l != i && r != i && a[l] + a[r] == target){
                cout << m[a[l]] << " " << m[a[i]] << " " << m[a[r]] << "\n";
                return 0;
            }else if(a[l] + a[r] < target){
                l++;
            }else{
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
