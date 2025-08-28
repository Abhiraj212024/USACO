#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> sentences(m);

    for(int i = 0; i < m; ++i){
        cin >> sentences[i];
    }

    for(auto word : sentences){
        for(int i = 0; i < k; ++i){
            for(auto c : word){
                for(int i = 0; i < k; ++i){
                    cout << c;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}