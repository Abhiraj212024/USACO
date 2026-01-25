#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void reverse(vector<int>& vec, int st, int end){ //O(n)
    int a = st;
    int b = end;
    while(a < b){
        swap(vec[a], vec[b]);
        a++;
        b--;
    }
}

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<int> p(n, 0);
        unordered_map<int, int> elem_idx;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            elem_idx[p[i]] = i;
        }

        int unsorted_idx = 0;
        while((p[unsorted_idx] + unsorted_idx) == n){
            unsorted_idx++;
        }

        if(unsorted_idx != n){
            reverse(p, unsorted_idx, elem_idx[n-unsorted_idx]);
        }

        for(int i = 0; i < n; i++){
            cout << p[i] << " ";
        }
        cout << "\n";

    }
    
    return 0;
}