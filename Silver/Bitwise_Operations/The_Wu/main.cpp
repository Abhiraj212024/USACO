#include <iostream>
#include <vector>
#include <climits>
#include <string>
#define ll long long
#define vll vector<ll>

const int MAX_K = 100;

using namespace std;

int to_int(const string& s){
    int n = s.length();
    int val = 0;
    for(int i = 0;i < n; i++){
        if(s[i] == '1'){
            val += (1 << i);
        }
    }
    return val;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vll w(n, 0);
    for(int i = 0; i < n; i++) cin >> w[i];

    vll wu(1 << n, 0);

    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                wu[i] += w[j];
            }
        }
    }

    vll counts(1 << n, 0);

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int val = to_int(s);
        counts[val]++;
    }

    vector<vll> pref_wu((1 << n), vll(MAX_K+1, 0));

    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < (1 << n); j++){
            int all_same = (1 << n) - 1;
            int mask = i ^ j;
            int wu_value = wu[all_same] - wu[mask];
            if(wu_value <= MAX_K){
                pref_wu[i][wu_value] += counts[j];
            }
        }

        for(int j = 1; j <= MAX_K; j++){
            pref_wu[i][j] += pref_wu[i][j-1];
        }
    }

    while(q--){
        string t;
        int k;
        cin >> t >> k;

        int val = to_int(t);

        cout << pref_wu[val][k] << "\n";
    }

    return 0;
}
