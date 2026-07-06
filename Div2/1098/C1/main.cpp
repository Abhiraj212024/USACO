#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long a;
        int n;
        cin >> a >> n;
        vector<int> d(n);
        for(int i = 0; i < n; i++) cin >> d[i];


        // case a == b trivial -> 0
        /**
         * Case a < b
         * Start iterating from the most significant to least significant
         * Keep adding the common digits (the prefix)
         * x -> first digit in a (from left) that can't be formed, y -> digit to be picked from d
         * assign y -> first d_i st d_i > x  (upper bound) assign all next digits as d_1 (smallest)
         */
        /**
         * Case a > b
         * Start iterating from the most significant to least significant
         * Keep adding the common digits (the prefix)
         * x -> first digit in a (from left) that can't be formed, y -> digit to be picked from d
         * assign y -> first d_i st d_i < x  (lower bound) assign all next digits as d_n (smallest)
         */

        // keep track of min diff as you keep adding digits

        long long temp = a;
        long long pow = 1;
        long long b_eq = 0;
        long long b_lt = 0;
        long long b_gt = 0;
        while(temp){
            pow *= 10;
            temp /= 10;
        }
        bool gt = false;
        bool eq = false;
        bool lt = false;
        temp = a;
        pow /= 10;
        while(temp){
            // msd = (temp) / pow
            int msd = temp / pow;
            int next_greater_idx = lower_bound(d.begin(), d.end(), msd) - d.begin();
            int prev_lower_idx = upper_bound(d.begin(), d.end(), msd) - d.begin();

            if(next_greater_idx >= 0 && next_greater_idx < n){
                if(d[next_greater_idx] == msd){ // if equal then add that digit
                    b_eq += (msd * pow);
                    b_lt += (msd * pow);
                    b_gt += (msd * pow);
                    eq = true;
                    lt = false;
                    gt = false;
                }else{
                    // can't be equal now, assign the this digit to b_gt and move on to d_1
                    b_gt += (d[next_greater_idx] * pow);
                    eq = false;
                    lt = false;
                    gt = true;
                    break;
                }
            }else if(prev_lower_idx >= 0 && prev_lower_idx < n){
                b_lt += (d[prev_lower_idx] * pow);
                eq = false;
                lt = true;
                gt = false;
                break;
            }

            temp = temp % pow;
            pow /= 10;

        }
        long long min_diff = LLONG_MAX;
        if(eq && !gt && !lt){
            cout << abs(b_eq - a) << "\n";
        }else if(!eq && gt && !lt){
            while(temp){
                b_gt += (d[0] * pow);
                min_diff = min(min_diff, abs(a-b_gt));
                temp = temp % pow;
                pow /= 10;
            }
        }else if(!eq && !gt && lt){
            while(temp){
                b_lt += (d[n-1] * pow);
                min_diff = min(min_diff, abs(a-b_lt));
                temp = temp % pow;
                pow /= 10;
            }
        }

        cout << min_diff << "\n";
    }
    return 0;
}