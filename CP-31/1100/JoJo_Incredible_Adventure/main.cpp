#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        int zero_count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') zero_count++;
        }
        if(zero_count == s.length()){
            cout << 0 << "\n";
            continue;
        }else if(zero_count == 0){
            ll area = (ll)(s.length()) * (ll)(s.length());
            cout << area << "\n";
            continue;
        }

        int cont_one = 0;
        int n = s.length();
        int i = 0;
        while(i < n){
            int count = 0;
            if(s[i] == '1'){
                while(i < n && s[i] == '1'){
                    count++;
                    i++;
                }
                if(i >= n){
                    int j = 0;
                    while(j < n && s[j] == '1'){
                        count++;
                        j++;
                    }
                }
                cont_one = max(cont_one, count);
            }else{
                i++;
            }
        }

        int st = cont_one;
        int end = 1;
        ll maxArea = 1;
        while(end <= st){
            ll area = (ll)(st) * (ll)(end);
            maxArea = max(maxArea, area);
            st--;
            end++;
        }

        cout << maxArea << "\n";
    }
    return 0;
}