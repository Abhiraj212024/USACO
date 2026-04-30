#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> sequences;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        int lo = 0;
        int hi = sequences.size();
        while(lo < hi){
            int mid = lo + (hi-lo)/2;

            if(sequences[mid].back() < a){
                // search for a greater possible
                hi = mid;
            }else{
                lo = mid+1;
            }
        }

        if(hi >= sequences.size() || hi < 0){
            // add new sequence
            sequences.push_back({a});
        }else{
            sequences[hi].push_back(a);
        }
    }


    for(const auto& vec : sequences){
        for(const auto& elem : vec){
            cout << elem << " ";
        }
        cout << "\n";
    }

    return 0;
}