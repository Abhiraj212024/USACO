#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int zero = 0;
        int one = 0;
        int two = 0;

        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a == 0){
                zero++;
            }else if(a == 1){
                one++;
            }else{
                two++;
            }
        }

        int n_ops = 0;
        n_ops += zero;
        int l1 = min(one, two);
        n_ops += l1;
        one -= l1;
        two -= l1;

        n_ops += (one / 3);
        n_ops += (two/3);

        cout << n_ops << "\n";

    }
    return 0;
}