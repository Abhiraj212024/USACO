#include <iostream>
using namespace std;

bool isPossible(long long total, long long n){

    long long a = (total - n) % (1 + 2*n);
    long long b = (total - n) / (1 + 2*n);
    return (a  == 0 && b <= n);
}

int main(){
    int t;
    cin >> t;
    while(t--){

        int p, q;
        cin >> p >> q;

        long long k = p + 2*q;

        // fix n

        // first true
        long long l = 1;
        long long r = 5e8;

        l--;
        while(l < r){
            long long mid = l + (r-l+1)/2;

            if(isPossible(k, mid)){
                l = mid;
            }else{
                r = mid-1;
            }
        }

        cout << r << "\n";

    }
    return 0;
}