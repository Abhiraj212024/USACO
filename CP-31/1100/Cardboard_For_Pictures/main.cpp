#include <iostream>
#include <vector>
#define ll long long
using namespace std;


int isValid(const vector<ll>& s, ll w, ll c){
    ll sum = 0;
    for(int i = 0; i < s.size(); i++){
        ll side = s[i] + 2*w;

        if(c / side < side){
            // to big
            return 1;
        }

        sum += side * side;

        if(sum > c){
            // to big
            return 1;
        }
    }

    if(sum == c) return 0;
    // too small;
    return -1;

}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        ll c;
        cin >> n >> c;

        vector<ll> s(n);

        for(int i = 0; i < n; i++) cin >> s[i];

        ll st = 1;
        ll end = 1e9;
        ll valid_w = -1;
        while(st <= end){
            ll w = st + (end-st)/2;
            int res = isValid(s, w, c);

            if(res == 0){
                valid_w = w;
                break;
            }else if(res > 0){
                // too big, reduce search
                end = w-1;
            }else{
                // too small
                st = w+1;
            }
        }

        cout << valid_w << "\n";
    }
    return 0;
}