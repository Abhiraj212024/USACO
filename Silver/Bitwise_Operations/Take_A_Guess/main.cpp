#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ask(int i, int j){

    int and_val = 0;
    fflush(stdout);
    cout << "and" << " " << i << " " << j << "\n";
    cin >> and_val;
    int or_val = 0;
    cout << "or" << " " << i << " " << j << "\n";
    fflush(stdout);
    cin >> or_val;

    int xor_val = ~(and_val)&(or_val);

    int sum = 2*(and_val) + xor_val;

    return sum;

}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    priority_queue<int> min_heap;
    int a1 = ask(1, 2);
    int a2 = ask(2, 3);
    int a3 = ask(1, 3);

    int a = (a1-a2+a3)/2;
    int b = (a1+a2-a3)/2;
    int c = (-a1+a2+a3)/2;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);

    for(int i = 0;i < 3; i++){
        min_heap.push(nums[i]);
        if(min_heap.size() > k){
            min_heap.pop();
        }
    }

    for(int i = 4; i <= n; i++){
        int x = ask(1, i);
        min_heap.push(x-a);
        if(min_heap.size() > k){
            min_heap.pop();
        }
    }

    cout << "finish" << " " << min_heap.top() << "\n";
    fflush(stdout);

    return 0;

}