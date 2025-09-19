#include <iostream>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> size(n);

    for(int i = 0; i<n; i++){
        cin >> size[i];
    }

    int max_count = INT_MIN;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = i+1; j < n; j++){
            if(abs(size[i] - size[j]) <= 3){
                count++;
            }
        }
        max_count = max(max_count, count);
    }

    max_count++; //include the testing diamond itself

    cout << max_count << "\n";

    return 0;
}