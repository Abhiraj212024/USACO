#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

int main(){

    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;

    if(m == 0){
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    vector<int> usb;
    vector<int> ps;

    for(int i = 0;i < m; i++){
        int val;
        string s;

        cin >> val >> s;

        if(s == "USB"){
            usb.push_back(val);
        }else{
            ps.push_back(val);
        }
    }

    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());

    vector<ll> usb_pref(usb.size());
    vector<ll> ps_pref(ps.size());

    
    if(!usb.empty()){
        
        usb_pref[0] = usb[0];
        for(int i = 1; i < usb.size(); i++){
            usb_pref[i] = usb_pref[i-1] + usb[i];
        }
    }

    if(!ps.empty()){

        ps_pref[0] = ps[0];
        for(int i = 1; i < ps.size(); i++){
            ps_pref[i] = ps_pref[i-1] + ps[i];
        }
    }

    // check on c1 and c2
    int max_equipped = 0;
    ll min_cost = LLONG_MAX;
    for(int c1 = 0; c1 <= c; c1++){
        int avail_usb = min(a + c1, (int)(usb.size()));
        int avail_ps = min(b + c - c1, (int)(ps.size()));

        ll usb_cost = (avail_usb >= 1) ? usb_pref[avail_usb - 1] : 0;
        ll ps_cost = (avail_ps >= 1) ? ps_pref[avail_ps - 1] : 0;

        ll cost = usb_cost +  ps_cost;
        if(avail_ps + avail_usb > max_equipped){
            max_equipped = avail_ps + avail_usb;
            min_cost = cost;
            continue;
        }else if(avail_ps + avail_usb == max_equipped){
            if(cost < min_cost){
                min_cost = cost;
            }
        }
    }


    cout << max_equipped << " " << min_cost << "\n";

    return 0;
}