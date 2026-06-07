#include <iostream>
#include <unordered_set>
#define ll long long
using namespace std;


ll gcd(ll a, ll b){
    // O(logn)
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    // O(log n)

    return (a*b) / (gcd(a, b));
}

ll sum_st_end(ll st, ll end){
    return ((end * (end + 1))/2) - ((st * (st-1))/2);
}


int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        
        ll lcm_x_y = lcm((ll)x, (ll)y);
        ll count1 = n/x - n/lcm_x_y;
        ll count2 = n/y - n/lcm_x_y;

        cout << sum_st_end(n-count1+1, n) - sum_st_end(1LL, count2) << "\n";
    }
    
    return 0;
}