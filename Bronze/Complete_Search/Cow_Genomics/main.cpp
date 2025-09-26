#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main(){

    vector<string> genomes;

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < (2*n); i++){
        string buff;
        cin >> buff;
        genomes.push_back(buff);
    }

    int ans = 0;

    for(int j = 0; j < m; j++){
        set<char> spotty, plain;
        for(int i = 0; i < n; i++) spotty.insert(genomes[i][j]);
        for(int i = n; i < 2*n; i++) plain.insert(genomes[i][j]);

        bool disjoint = true;
        for(char c : spotty){
            if(plain.count(c)){
                disjoint = false;
                break;
            }
        }

        if(disjoint) ans++;
    }

    cout << ans << "\n";

    return 0;
}