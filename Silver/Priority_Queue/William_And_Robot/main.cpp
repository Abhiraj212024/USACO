#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> min_heap;

    for(int k = 1; k <= n; k++){
        min_heap.push(a[k-1]);
        if(k % 2 == 0){
            while(min_heap.size() > (k/2)) min_heap.pop();
        }
    }

    ll sum = 0;
    while(!min_heap.empty()){
        sum += min_heap.top();
        min_heap.pop();
    }

    cout << sum << "\n";

    return 0;
}