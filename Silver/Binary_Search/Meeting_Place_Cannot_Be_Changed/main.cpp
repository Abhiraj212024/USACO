#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
#define LL long long

using namespace std;

bool isPossible(const vector<int>& x, const vector<int>& v, double t){
    double lower_point = -1e17;
    double upper_point = 1e17;

    for(int i = 0; i < x.size(); i++){
        double left = (double)(x[i]) - t * (double)(v[i]);  // micro meter
        double right = (double)(x[i]) + t * (double)(v[i]); // micro meter

        lower_point = max(lower_point, left);
        upper_point = min(upper_point, right);
    }

    return (lower_point <= upper_point); // must be an intersection
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n, 0);
    vector<int> v(n, 0);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    double lo = 0;
    double hi = 1e9;

    while(lo < hi){
        double mid = lo + (hi - lo)/2.0;

        if(isPossible(x, v, mid)){
            hi = mid - 1e-6;
        }else{
            lo = mid + 1e-6;
        }
    }


    cout << fixed << setprecision(12) << hi << "\n";

    return 0;
}