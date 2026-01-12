#include <iostream>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int in;
        cin >> in;
        if(in == 2){
            cout << 2 << "\n";
            continue;
        }

        if(in == 3){
            cout << 3 << "\n";
            continue;
        }

        if(in % 2 == 0){
            cout << 0 << "\n";
            continue;
        }

        if(in % 2 == 1){
            cout << 1 << "\n";
            continue;
        }
    }
    return 0;

}
