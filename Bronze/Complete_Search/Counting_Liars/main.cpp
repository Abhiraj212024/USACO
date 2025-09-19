#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> p(n);
    vector<char> s(n);

    for(int i = 0; i < n; i++){
        cin >> s[i] >> p[i];
    }

    int min_lies = INT_MAX;

    for(int i = 0; i < n; i++){
        for(int candidate : {p[i], p[i]-1, p[i] + 1}){
            int lies = 0;
            for(int j = 0; j < n; j++){
                if(s[j] == 'L'){
                    if(candidate > p[j]) lies++;
                }else{
                    if(candidate < p[j]) lies++;
                }
            }
            min_lies = min(min_lies, lies);
        }
    }

    cout << min_lies << "\n";

    return 0;
}