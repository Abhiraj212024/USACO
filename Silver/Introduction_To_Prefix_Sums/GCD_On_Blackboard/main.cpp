#include <iostream>
#include <vector>
#define LL long long

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    if(a == 0) return b;
    return gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n+1, 0);
    vector<int> l_gcd(n+1, 0);
    vector<int> r_gcd(n+1, 0);
    for(int i{1}; i <= n; i++){
        cin >> a[i];
        l_gcd[i] = gcd(l_gcd[i-1], a[i]);
    }
    for(int i = n-1; i >= 0; i--){
        r_gcd[i] = gcd(r_gcd[i+1], a[i+1]);
    }

    int max_gcd = INT_MIN;

    for(int i{1}; i <= n; i++){
        max_gcd = max(max_gcd, gcd(l_gcd[i-1], r_gcd[i]));
    }

    cout << max_gcd << "\n";
    return 0;
}
