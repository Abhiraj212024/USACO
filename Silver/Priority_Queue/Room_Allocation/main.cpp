#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Guest{
    int arrival;
    int departure;
    int idx;
};

bool compareGuests(const Guest& g1, const Guest& g2){
    if(g1.arrival == g2.arrival){
        return g1.departure < g2.departure;
    }
    return g1.arrival < g2.arrival;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Guest> guests(n);
    for(int i = 0; i < n; i++){
        cin >> guests[i].arrival >> guests[i].departure;
        guests[i].idx = i;
    }

    sort(guests.begin(), guests.end(), compareGuests); // sort by arrival time

    // min heap stores pairs {departure time, idx}    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    vector<int> ans(n);
    int max_rooms = 0;

    for(int i = 0; i < n; i++){
        if(!min_heap.empty() && guests[i].arrival > min_heap.top().first){ // arrival after departure
            int reused_room = min_heap.top().second;
            ans[guests[i].idx] = reused_room; 
            min_heap.pop();
            min_heap.push({guests[i].departure, reused_room});
        }else{
            max_rooms++;
            ans[guests[i].idx] = max_rooms;
            min_heap.push({guests[i].departure, max_rooms});
        }
    }

    cout << max_rooms << "\n";
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}