#include <iostream>
#include <vector>

using namespace std;

int query(int op ,int l, int r){
    cout << op << " " << l << " " << r << flush << "\n";
    int x;
    cin >> x;
    return x;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = 1;
        int r = n;

        while(l < r){
            int mid = l + (r - l) / 2;
            int pi = query(1, 1, mid);
            int qi = query(2, 1, mid);

            if(pi < qi) r = mid;
            else l = mid+1;
        }

        int sum = query(2, 1, n);
        sum -= (n * (n+1)) / 2;
        int diff = sum - 1;

        cout << "!" << " " << l << " " << diff + l << flush << "\n";

    }

    return 0;
}
