#include <math.h>
#include <util.h>
#include <iostream>
#include <vector>
using namespace std;

bool is_square(int x){ 
    int r = sqrt(x);
    return r * r == x;
}

// Case A: r1, r2, r3 placed horizontally
bool caseA(pair<int,int> a, pair<int,int> b, pair<int,int> c, int S){
    return a.second == S && b.second == S && c.second == S &&
           a.first + b.first + c.first == S;
}

// Case B: r1 on top, r2 and r3 below
bool caseB(pair<int,int> a, pair<int,int> b, pair<int,int> c, int S){
    return a.first == S &&
           b.second == c.second &&
           b.second + a.second == S &&
           b.first + c.first == S;
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int total = x1*y1 + x2*y2 + x3*y3;
    if(!is_square(total)){
        cout << -1 << endl;
        return 0;
    }

    int S = sqrt(total);
    vector<pair<int,int>> rects = {{x1,y1},{x2,y2},{x3,y3}};
    vector<char> lab = {'A','B','C'};

    // 6 permutations of rectangles
    vector<int> p = {0,1,2};

    do {
        // 8 rotation combinations
        for(int mask=0; mask<8; mask++){
            vector<pair<int,int>> r(3);

            for(int i=0;i<3;i++){
                int x = rects[p[i]].first;
                int y = rects[p[i]].second;
                if(mask & (1<<i)) swap(x,y); // rotate
                r[i] = {x,y};
            }

            // Try Case A
            if(caseA(r[0],r[1],r[2],S)){
                cout << S << "\n";
                for(int i=0;i<r[0].second;i++){
                    cout << string(r[0].first, lab[p[0]]);
                    cout << string(r[1].first, lab[p[1]]);
                    cout << string(r[2].first, lab[p[2]]);
                    cout << "\n";
                }
                return 0;
            }

            // Try Case B
            if(caseB(r[0],r[1],r[2],S)){
                cout << S << "\n";

                // top block (r1)
                for(int i=0;i<r[0].second;i++){
                    cout << string(S, lab[p[0]]) << "\n";
                }

                // bottom blocks r2 and r3
                for(int i=0;i<r[1].second;i++){
                    cout << string(r[1].first, lab[p[1]]);
                    cout << string(r[2].first, lab[p[2]]);
                    cout << "\n";
                }

                return 0;
            }

        }
    } while(next_permutation(p.begin(),p.end()));

    cout << -1 << endl;
    return 0;
}
