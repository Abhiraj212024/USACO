#include <iostream>
#include <climits>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll first = 0;
        if(n % 12 <= 9){
            first = n%12;
        }else if(n % 12 == 10){
            first = 22;
        }else if(n % 12 == 11){
            first = 11;
        }

        ll second = n - first;
        if(second < 0){
            cout << -1 << "\n";
        }else{
            cout << first << " " << second << "\n";
        }
    }
    return 0;
}