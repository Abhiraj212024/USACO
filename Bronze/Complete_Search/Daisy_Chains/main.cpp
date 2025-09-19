#include <iostream>
#include <unordered_set>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> petals(n);
    for(int i = 0; i < n; i++){
        cin >> petals[i];
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        int sum = 0;
        unordered_set<int> seen;
        for(int j = i; j < n; j++){
            sum += petals[j];
            int len = j-i+1;
            seen.insert(petals[j]);
            if(sum % len == 0){
                int avg = sum / len;
                if(seen.count(avg)){
                    count++;
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}