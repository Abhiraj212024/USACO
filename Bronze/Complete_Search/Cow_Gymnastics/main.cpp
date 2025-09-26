#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main(){

    int k,n;
    cin >> k >> n;

    vector<vector<int>> matrix;

    for(int i = 0; i < k; i++){
        vector<int> buffer(n);
        for(int j = 0; j < n; j++){
            cin >> buffer[j];
        }
        matrix.push_back(buffer);
    }

    set<pair<int, int>> pairs;
    set<pair<int, int>> deleted;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                pair<int, int> curr = {matrix[i][j], matrix[i][k]};
                pair<int, int> buff = {matrix[i][k], matrix[i][j]};

                if(deleted.count(buff) || deleted.count(curr)) continue;

                auto it = pairs.find(buff);
                if((it == pairs.end())){
                    pairs.insert(curr);
                }else{
                    deleted.insert(curr);
                    deleted.insert(buff);
                    pairs.erase(it);
                }
            }
        }
    }

    cout << pairs.size() << "\n";

    return 0;
}