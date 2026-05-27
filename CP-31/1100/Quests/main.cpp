#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(i == 0){
                a[i] = x;
            }else{
                a[i] = a[i-1] + x;
            }
        }
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(i == 0){
                b[i] = x;
            }else{
                b[i] = max(b[i-1], x);
            }
        }
        int max_exp = 0;
        for(int i = 0; i < min(n, k); i++){
            max_exp = max(max_exp, a[i] + (k - i - 1)*b[i]);
        }

        cout << max_exp << "\n";
    }
    
    return 0;
}