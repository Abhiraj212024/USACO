#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int process_alice(int n){
    while(n--){
        cout << 1 << " " << 2 << "\n";
        int a, c;
        cin >> a >> c;
        if(a == -1 || c == -1) return 1;
    }

    return 0;
}

int process_bob(int n, const vector<int>& color) {
    queue<int> c1; // Group 1 (prefers color 1)
    queue<int> c2; // Group 2 (prefers color 2)
    
    // Note: your color array uses 1 and 2, but 0-indexed nodes
    for (int i = 0; i < n; i++) {
        if (color[i] == 1) c1.push(i + 1); // 1-based indexing for output
        else c2.push(i + 1);
    }

    for (int round = 0; round < n; round++) {
        int a, b;
        cin >> a >> b;
        if (a == -1 || b == -1) return 1; // Interactor error/termination

        // Case 1: Alice gives 1 and 2
        if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
            if (!c1.empty()) {
                cout << c1.front() << " " << 1 << endl;
                c1.pop();
            } else {
                cout << c2.front() << " " << 2 << endl;
                c2.pop();
            }
        }
        // Case 2: Alice gives 1 and 3
        else if ((a == 1 && b == 3) || (a == 3 && b == 1)) {
            if (!c1.empty()) {
                cout << c1.front() << " " << 1 << endl;
                c1.pop();
            } else {
                // Group 1 is empty, so we must use color 3 on Group 2
                cout << c2.front() << " " << 3 << endl;
                c2.pop();
            }
        }
        // Case 3: Alice gives 2 and 3
        else if ((a == 2 && b == 3) || (a == 3 && b == 2)) {
            if (!c2.empty()) {
                cout << c2.front() << " " << 2 << endl;
                c2.pop();
            } else {
                // Group 2 is empty, so we must use color 3 on Group 1
                cout << c1.front() << " " << 3 << endl;
                c1.pop();
            }
        }
    }
    return 0;
}

int solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool isBipartite = true;

    vector<int> color(n, 0); // 0 1 2
    queue<int> q;
    q.push(0);
    color[0] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(const int& v : adjList[u]){
            if(color[v] == 0){
                color[v] = (color[u] == 1) ? 2 : 1;
                q.push(v);
            }else{
                if(color[u] == color[v]){
                    isBipartite = false;
                    break;
                }
            }
        }

        if(!isBipartite) break;
    }



    if(!isBipartite){
        cout << "Alice\n";
        // process for alice
        if(process_alice(n)) return 1; // break program
    }else{
        cout << "Bob\n";
        if(process_bob(n, color)) return 1; // terminate program
    }
    return 0;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        if(solve()) return 1;
    }
    return 0;
}