#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    deque<int> vs;
    deque<int> ls;
    deque<int> vb;
    deque<int> lb;

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ls.push_back(a);
        vs.push_back(b);
    }
    
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        lb.push_back(a);
        vb.push_back(b);
    }

    int max_diff = 0;

    while(!lb.empty() && !ls.empty()){

        if(lb.front() < ls.front()){
            max_diff = max(max_diff, vb.front() - vs.front());
            int distance_def = ls.front()-lb.front();
            ls.pop_front();
            lb.pop_front();
            ls.push_front(distance_def);
            vb.pop_front();
        }else if(lb.front() > ls.front()){
            max_diff = max(max_diff, vb.front()-vs.front());
            int distance_def = lb.front() - ls.front();
            ls.pop_front();
            lb.pop_front();
            lb.push_front(distance_def);
            vs.pop_front();
        }else{
            max_diff = max(max_diff, vb.front()-vs.front());
            ls.pop_front();
            lb.pop_front();
            vs.pop_front();
            vb.pop_front();
        }
    }

    cout << max_diff << endl;

    return 0;
}