#include <iostream>
#include <map>
#include <set>
using namespace std;

int intersections(const set<string>& s1, const set<string>& s2){
    int ans = 0;
    for(const string& s : s1){
        if(s2.count(s)) ans++;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> animals;
    vector<set<string>> chars;
    for(int i = 0; i < n; i++){
        string animal;
        int k;
        cin >> animal >> k;
        set<string> buff;
        for(int j = 0; j < k; j++){
            string characteristic;
            cin >> characteristic;
            buff.insert(characteristic);
        }
        animals.push_back(animal);
        chars.push_back(buff);
    }

    int k = 0;

    for(int i = 0; i < n; i++){
        set<string> s1 = chars[i];
        for(int j = i+1; j < n; j++){
            k = max(k, intersections(s1, chars[j]));
        }
    }

    cout << k+1 << "\n";
    return 0;
}